import os
import sys
import socket
import hashlib
import zipfile
from threading import Thread

# 配置常量
PORT = 33450
BUFFER_SIZE = 4096
TEMP_ZIP_NAME = "_temp_transfer.zip"

# 工具函数：计算文件哈希
def compute_sha256(file_path):
    sha256 = hashlib.sha256()
    with open(file_path, 'rb') as f:
        while chunk := f.read(BUFFER_SIZE):
            sha256.update(chunk)
    return sha256.hexdigest()

# 工具函数：打包文件夹
def pack_folder(path):
    with zipfile.ZipFile(TEMP_ZIP_NAME, 'w', zipfile.ZIP_DEFLATED) as zipf:
        for root, dirs, files in os.walk(path):
            for file in files:
                abs_path = os.path.join(root, file)
                rel_path = os.path.relpath(abs_path, start=path)
                zipf.write(abs_path, rel_path)
    return TEMP_ZIP_NAME

# 发送方逻辑
def send_file(ip, path):
    try:
        # 预处理路径
        if os.path.isdir(path):
            print("[+] 正在打包文件夹...")
            file_to_send = pack_folder(path)
            is_folder = True
        else:
            file_to_send = path
            is_folder = False

        # 计算哈希
        file_hash = compute_sha256(file_to_send)
        file_size = os.path.getsize(file_to_send)
        file_name = os.path.basename(file_to_send)

        # 建立连接
        print(f"[+] 正在连接 {ip}:{PORT}...")
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((ip, PORT))
            
            # 发送元数据
            meta = f"{file_hash}|{file_size}|{file_name}|{is_folder}"
            s.sendall(meta.encode('utf-8'))
            s.recv(1)  # 等待确认
            
            # 发送文件内容
            print(f"[+] 正在发送数据 ({file_size/1024/1024:.2f} MB)...")
            with open(file_to_send, 'rb') as f:
                while chunk := f.read(BUFFER_SIZE):
                    s.sendall(chunk)
            
        print("[√] 传输完成")
        
    finally:
        if os.path.exists(TEMP_ZIP_NAME):
            os.remove(TEMP_ZIP_NAME)

# 接收方逻辑
def start_receiver():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('0.0.0.0', PORT))
        s.listen()
        print(f"[*] 正在监听端口 {PORT}...")

        while True:
            conn, addr = s.accept()
            Thread(target=handle_connection, args=(conn, addr)).start()

def handle_connection(conn, addr):
    try:
        print(f"\n[+] 收到来自 {addr} 的连接")
        
        # 接收元数据
        meta = conn.recv(1024).decode('utf-8').split('|')
        file_hash, file_size, file_name, is_folder = meta
        file_size = int(file_size)
        is_folder = eval(is_folder)
        
        conn.send(b'1')  # 发送确认
        
        # 接收文件内容
        received_bytes = 0
        temp_file = f"RECV_{file_name}"
        with open(temp_file, 'wb') as f:
            while received_bytes < file_size:
                chunk = conn.recv(min(BUFFER_SIZE, file_size - received_bytes))
                if not chunk:
                    break
                f.write(chunk)
                received_bytes += len(chunk)
        
        # 校验完整性
        print("[+] 正在校验文件...")
        actual_hash = compute_sha256(temp_file)
        if actual_hash == file_hash:
            print("[√] 校验成功")
            
            # 处理文件夹解包
            if is_folder and temp_file.endswith(".zip"):
                extract_dir = os.path.splitext(temp_file)[0]
                with zipfile.ZipFile(temp_file, 'r') as zip_ref:
                    zip_ref.extractall(extract_dir)
                os.remove(temp_file)
                print(f"[√] 文件夹已解压到：{extract_dir}")
            else:
                new_name = input("输入保存文件名（直接回车保持原文件名）：").strip()
                final_name = new_name if new_name else file_name
                os.rename(temp_file, final_name)
                print(f"[√] 文件保存为：{final_name}")
        else:
            print("[!] 文件损坏！已删除临时文件")
            os.remove(temp_file)
            
    except Exception as e:
        print(f"[!] 错误：{str(e)}")
    finally:
        conn.close()

# 命令行界面
def main():
    print("""局域网文件传输工具
命令列表：
  send    - 发送文件/文件夹
  receive - 进入接收模式
  exit    - 退出程序""")

    while True:
        cmd = input("\n>>> ").lower()
        
        if cmd == 'send':
            ip = input("输入接收方IP地址: ").strip()
            path = input("输入要发送的文件/文件夹路径: ").strip()
            if os.path.exists(path):
                Thread(target=send_file, args=(ip, path)).start()
            else:
                print("[!] 路径不存在")
                
        elif cmd == 'receive':
            print("[*] 进入接收模式...")
            start_receiver()
            
        elif cmd == 'exit':
            sys.exit(0)
            
        else:
            print("未知命令")

if __name__ == "__main__":
    main()