import pyzipper
import os

folder_name = os.getcwd()
zip_file = "test.zip"
password = "1234"

with pyzipper.AESZipFile(zip_file, 'w') as zip:
    zip.setpassword(password.encode())
    zip.setencryption(pyzipper.WZ_AES,nbits = 256)

    for root ,_ , files in os.walk(folder_name):
        for original_file in files:
            file_path = os.path.join(root, original_file)
            file_path = os.path.relpath(file_path, folder_name)
            # print(file_path)
            zip.write(file_path, arcname = file_path)