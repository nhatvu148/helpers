import tkinter as tk
from tkinter import filedialog

def main():
    root = tk.Tk()
    root.iconbitmap('../assets/img/icon.ico')
    root.withdraw()

    file_path = filedialog.askopenfilename(title="Select a License file", filetypes=(("License files", ".key .lic .txt"),("All files", "*.*")))
    
    return file_path
    
if __name__ == "__main__":
    file_path = main()
    print(file_path)