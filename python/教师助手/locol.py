
import psutil
import subprocess
import time
import sys
import os

# 配置区
STUDENTMAIN_PATH = r"C:\Program Files\Mythware\极域课堂管理系统软件V6.0 2016 豪华版\StudentMain.exe"
CHECK_INTERVAL = 3  # 检测间隔 3 秒

def is_network_connected():
    """检测有线网络接口物理连接状态"""
    stats = psutil.net_if_stats()
    for intf, stat in stats.items():
        # 通过接口名称识别有线网络（兼容中英文系统）
        if ("以太网" in intf or "Ethernet" in intf) and stat.isup:
            return True
    return False

def check_and_restart_process():
    """检查并重启StudentMain.exe"""
    # 检查进程是否已存在
    for proc in psutil.process_iter(['name']):
        if proc.info['name'].lower() == "studentmain.exe":
            return
    
    # 进程不存在时尝试启动
    if os.path.exists(STUDENTMAIN_PATH):
        try:
            subprocess.Popen(
                [STUDENTMAIN_PATH],
                creationflags=subprocess.CREATE_NO_WINDOW
            )
            print(f"[Action] 已启动: {STUDENTMAIN_PATH}")
        except Exception as e:
            print(f"[Error] 启动失败: {e}")
    else:
        print(f"[Error] 程序路径不存在: {STUDENTMAIN_PATH}")

def main_loop():
    while True:
        # 网络连接检测
        if not is_network_connected():
            print("[Warning] 有线网络未连接！")
        
        # 进程状态检测
        check_and_restart_process()
        
        time.sleep(CHECK_INTERVAL)

if __name__ == "__main__":
    if not psutil.WINDOWS:
        print("此脚本仅支持Windows系统。")
        sys.exit(1)
    
    try:
        main_loop()
    except KeyboardInterrupt:
        print("\n程序已安全退出。")
        sys.exit(0)