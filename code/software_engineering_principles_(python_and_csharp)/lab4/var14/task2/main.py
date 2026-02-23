import tkinter as tk
from tkinter import messagebox

class App:
    def __init__(self):
        self.font = ("Arial, 18")

        self.root = tk.Tk()
        self.root.title("Working With Files")
        self.build_widgets()
        self.root.mainloop()
    
    def build_widgets(self):
        self.build_button = tk.Button(self.root, text="Create TF_1", command=self.create_tf1, font=self.font)
        self.build_button.pack(pady=5)

        self.process_button = tk.Button(self.root, text="Move From TF_1 to TF_2", command=self.process_files, font=self.font)
        self.process_button.pack(pady=5)

        self.read_button = tk.Button(self.root, text="Read TF_2", command=self.display_tf2, font=self.font)
        self.read_button.pack(pady=5)

        self.text_area = tk.Text(self.root, width=50, height=20, font=self.font)
        self.text_area.pack(padx=10, pady=10)
    
    def create_tf1(self):
        lines = [
            "Hell111oaaaaaaaaa111",
            "Goodbye222",
            "33CHNU",
            "PYTH44ON",
        ]
        with open("TF_1.txt", "w", encoding="utf-8") as file:
            for line in lines:
                file.write(line + " ")
    
    def process_files(self):
        try:
            with open("TF_1.txt", "r", encoding="utf-8") as tf_1, \
                 open("TF_3.txt", "w", encoding="utf-8") as tf_3:
                content = tf_1.read()
                digits = "".join(filter(str.isdigit, content))
                other = "".join(filter(lambda c: not c.isdigit() and c != '\n', content))
                output = digits + other
                for i in range(0, len(output), 10):
                    tf_3.write(output[i:i+10] + "\n")

            with open("TF_3.txt", "r", encoding="utf-8") as tf_3, \
                 open("TF_2.txt", "w", encoding="utf-8") as tf_2:
                tf_2.write(tf_3.read())

        except FileNotFoundError:
            messagebox.showerror("Error", "No TF_1")
        except Exception as exception:
            messagebox.showerror("Error", str(exception))

    def display_tf2(self):
        try:
            with open("TF_2.txt", "r", encoding="utf-8") as f2:
                self.text_area.delete(1.0, tk.END)
                self.text_area.insert(tk.END, f2.read())
        except FileNotFoundError:
            messagebox.showerror("Error", "No file TF_2")
        except Exception as exception:
            messagebox.showerror("Error", str(exception))

        
            

def main():
    App()

if __name__ == "__main__":
    main()