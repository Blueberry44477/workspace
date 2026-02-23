import tkinter as tk
from tkinter import messagebox, filedialog
import logging
import os
from datetime import datetime

class CalculatorApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Calculator")

        self.setup_logging()

        self.font = ("Arial", 18)
        # Calculations 
        self.num1_var = tk.StringVar()
        self.num2_var = tk.StringVar()
        self.operation_var = tk.StringVar(value="+")

        self.build_widgets()
    
    def build_widgets(self):
        tk.Label(self.root, text="Number 1:", font=self.font).pack(padx=10, pady=2, anchor="w")
        self.entry_num1 = tk.Entry(self.root, textvariable=self.num1_var, font=self.font)
        self.entry_num1.pack(fill="x", padx=10)

        tk.Label(self.root, text="Number 2:", font=self.font).pack(padx=10, pady=2, anchor="w")
        self.entry_num2 = tk.Entry(self.root, textvariable=self.num2_var, font=self.font)
        self.entry_num2.pack(fill="x", padx=10)

        tk.Label(self.root, text="Operation:", font=self.font).pack(padx=10, pady=5, anchor="w")
        operation_frame = tk.Frame(self.root)
        operation_frame.pack(padx=10, pady=5)
        
        # Radiobuttons
        for op in ["+", "-", "*", "/", "^"]:
            tk.Radiobutton(operation_frame, text=op, value=op, 
                           variable=self.operation_var, font=self.font).pack(side="left", padx=5)

        buttons_frame = tk.Frame(self.root)
        buttons_frame.pack(pady=10)

        tk.Button(buttons_frame, text="Import", command=self.import_data, font=self.font).grid(row=0, column=0, padx=5)
        tk.Button(buttons_frame, text="Calculate", command=self.calculate, font=self.font).grid(row=0, column=1, padx=5)
        tk.Button(buttons_frame, text="Export", command=self.export_result, font=self.font).grid(row=0, column=2, padx=5)

        tk.Label(self.root, text="Result:", font=self.font).pack(anchor="w", padx=10, pady=2)
        self.result_text = tk.Text(self.root, height=3, font=self.font)
        self.result_text.pack(fill="both", expand=True, padx=10, pady=5)

        self.result_str = ""

    def setup_logging(self):
        session_start = datetime.now().strftime("%d-%m-%Y_%H:%M:%S")
        self.log_filename = f"{"Session_log_" + session_start}.txt"
        logging.basicConfig(filename=self.log_filename,
                            level=logging.INFO,
                            format="%(asctime)s - %(message)s",
                            datefmt="%Y-%m-%d %H:%M:%S")
        logging.info("Session Start")

    def import_data(self):
        # File Selection
        file_path = filedialog.askopenfilename(
            title="Choose Input File",
            filetypes=[("Text files", "*.txt")]
        )
        if not file_path:
            return

        try:
            with open(file_path, "r", encoding="utf-8") as file:
                data = file.read().strip().split()
                if len(data) < 2:
                    raise ValueError("File must have at least two numbers.")
                self.num1_var.set(data[0])
                self.num2_var.set(data[1])
            logging.info(f"Data import from file: {file_path} → {data}")
            messagebox.showinfo("Success", "Import Successful.")
        except Exception as e:
            logging.error(f"Import Error: {e}")
            messagebox.showerror("Failure", f"Failed to import data:\n{e}")

    def calculate(self):
        try:
            num1 = float(self.num1_var.get())
            num2 = float(self.num2_var.get())
            op = self.operation_var.get()

            if op == "+":
                result = num1 + num2
            elif op == "-":
                result = num1 - num2
            elif op == "*":
                result = num1 * num2
            elif op == "/":
                if num2 == 0:
                    raise ZeroDivisionError("Don`t try to divide by zero...")
                result = num1 / num2
            elif op == "^":
                result = num1 ** num2
            else:
                raise ValueError("Unknown Operation.")

            self.result_str = f"{num1} {op} {num2}, Result: {result}"
            # Update UI
            self.result_text.delete(1.0, tk.END)
            self.result_text.insert(tk.END, self.result_str)

            logging.info(f"Calculation: {self.result_str}")

        except ValueError as exception:
            logging.exceptionrror(f"Failure: {exception}")
            messagebox.showerror("Failure", f"Wrong Data: {exception}")
        except Exception as exception:
            logging.error(f"Failure: {exception}")
            messagebox.showerror("Failure", str(exception))

    def export_result(self):
        if not self.result_str:
            messagebox.showwarning("Warning", "Nothing To Export.")
            return

        file_path = filedialog.asksaveasfilename(
            title="Save Result",
            defaultextension=".txt",
            filetypes=[("Text files", "*.txt"), ("All files", "*.*")]
        )
        if not file_path:
            return

        try:
            with open(file_path, "w", encoding="utf-8") as file:
                file.write(self.result_str)
            logging.info(f"Export to: {file_path}")
            messagebox.showinfo("Success", "Export Succeeded.")
        except Exception as exception:
            logging.error(f"Export Failure: {exception}")
            messagebox.showerror("Error", f"Failed to export:\n{exception}")

    def __del__(self):
        logging.info("Session End")

if __name__ == "__main__":
    root = tk.Tk()
    app = CalculatorApp(root)
    root.mainloop()

