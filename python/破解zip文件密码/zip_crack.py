import pyzipper
import tkinter as tk
from tkinter import messagebox
from tkinter import filedialog
from tkinter.scrolledtext import ScrolledText
import threading
import time

#TK设置
root = tk.Tk()
root.title("zip密码破解工具")
root.geometry("400x400+50+50")
root.resizable(False, False)

#全局变量
pwdbook_path = "K:/私人文件夹/1-信息学/2-Python/项目/密码文件/common.txt"
zip_path = "K:/私人文件夹/1-信息学/2-Python/项目/破解zip文件密码/test/test.zip"
extract_to = "K:/私人文件夹/1-信息学/2-Python/项目/破解zip文件密码/extract"

def zip_crack():
    global pwdbook_path
    global zip_path
    global extract_to
    try:
        with open(pwdbook_path, "r") as password_file:
            for pwd in password_file:
                pwd = pwd.strip()
                try:
                    with pyzipper.AESZipFile(zip_path) as zip_file:
                        zip_file.extractall(path = extract_to, pwd = pwd.encode('utf-8'))
                    events_text.insert(tk.END, f"密码为:{pwd}\n")
                    messagebox.showinfo("Zip密码破解", f"密码为:{pwd}")
                    pwd_entry.delete(0, tk.END)# 清空原有内容
                    pwd_entry.insert(0, pwd)# 插入新内容
                    return pwd
                except Exception as e:
                    events_text.insert(tk.END, f"密码错误:{pwd}\n")
                time.sleep(0.05)
    except IOError:
        pwdbook_path_entry.delete(0, tk.END)# 清空原有内容
        pwdbook_path_entry.insert(0,"密码本不存在!")# 插入新内容
        pwdbook_path = ''
    return None

def start_zip_crack():
    if pwdbook_path == '' or zip_path == '':
        if pwdbook_path == '':
            messagebox.showinfo("破解密码", f"请输入密码本路径!")
        if zip_path == '':
            messagebox.showinfo("破解密码", f"请输入zip文件路径!")
        return None
    pwd = zip_crack()
    pwd_entry.insert(0, str(pwd))
    root.mainloop()

def startcrack():
    crack = threading.Thread(target = zip_crack)
    crack.start()

def open_zip_file():
    global zip_path
    filetypes = (
        ('zip files', '*.zip'),
        ('All files', '*.*')
    )
    filename = filedialog.askopenfilename(
        title='打开ZIP文件',
        initialdir='/',
        filetypes=filetypes)
    if filename == '':
        return None
    zip_path = filename
    zip_path_entry.delete(0, tk.END)# 清空原有内容
    zip_path_entry.insert(0, zip_path)# 插入新内容

def open_pwdbook_file():
    global pwdbook_path
    filetypes = (
        ('text files', '*.txt'),
        ('All files', '*.*')
    )
    filename = filedialog.askopenfilename(
        title='打开文件',
        initialdir='/',
        filetypes=filetypes)
    if filename == '':
        return None
    pwdbook_path = filename
    pwdbook_path_entry.delete(0, tk.END)# 清空原有内容
    pwdbook_path_entry.insert(0, pwdbook_path)# 插入新内容

#创建界面
canvas = tk.Canvas(root, width=400, height=200)
canvas.create_line(10, 30, 390, 30, fill="grey")
canvas.create_line(10, 160, 390, 160, fill="grey")
canvas.create_line(10, 30, 10, 160, fill="grey")
canvas.create_line(390, 30, 390, 160, fill="grey")
pwdbook_path_label = tk.Label(root, text="密码本路径:")
pwdbook_path_entry = tk.Entry(root, width=20)
open_pwdbook_path = tk.Button(root, text='添加密码文件路径', command=open_pwdbook_file)
zip_path_label = tk.Label(root, text="zip文件路径:")
zip_path_entry = tk.Entry(root, width=20)
open_zip_path = tk.Button(root, text='添加zip文件路径', command=open_zip_file)
start_crack = tk.Button(root, text="开始破解", command = startcrack)
pwd_label = tk.Label(root, text="密码:")
pwd_entry = tk.Entry(root, width=20)
events_text = ScrolledText(root, width = 50, height = 17)

#打印页面
zip_path_label.place(x = 15, y = 85)
zip_path_entry.place(x = 95, y = 85)
open_zip_path.place(x = 270, y = 80)
pwdbook_path_label.place(x = 15, y = 125)
pwdbook_path_entry.place(x = 95, y = 125)
open_pwdbook_path.place(x = 270, y = 120)
start_crack.place(x = 15, y = 40)
pwd_label.place(x = 95, y = 45)
pwd_entry.place(x = 145, y = 45)
canvas.pack()
events_text.place(x = 15, y = 170)

#主程序
pwdbook_path_entry.delete(0, tk.END)# 清空原有内容
pwdbook_path_entry.insert(0, pwdbook_path)# 插入新内容
zip_path_entry.delete(0, tk.END)# 清空原有内容
zip_path_entry.insert(0, zip_path)# 插入新内容
root.mainloop()