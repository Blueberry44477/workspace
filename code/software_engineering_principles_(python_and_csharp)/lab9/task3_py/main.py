import tkinter as tk
from tkinter import ttk, filedialog, messagebox
from typing import Optional

class Stack:
    def __init__(self):
        self._data = []

    def push(self, value) -> None:
        self._data.append(value)
    
    def pop(self) -> None:
        if self.is_empty():
            raise IndexError("Stack Is Empty.")
        else:
            return self._data.pop()
    
    def is_empty(self) -> bool:
        return len(self._data) == 0
    
    def clear(self) -> None:
        self._data.clear()

class BracketChecker:
    def __init__(self):
        self.stack = Stack()
    
    def check_expression(self, expression: str) -> list[tuple[int, int]]|None:
        self.stack.clear()
        position_pairs = []

        for position, symbol in enumerate(expression, start=0):
            if symbol == '(':
                self.stack.push(position)
            elif symbol == ')':
                if self.stack.is_empty():
                    return None # Not balanced
                open_position = self.stack.pop()
                position_pairs.append((open_position, position))
        
        if not self.stack.is_empty():
            return None
        
        position_pairs.sort(key=lambda pair: pair[1])
        return position_pairs

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Task 3")
        self.checker = BracketChecker()
        self.build_ui()

    def _read_expr_from_file(self) -> None:
        file_path = filedialog.askopenfilename(
            title="Choose expression File.", 
            filetypes=[("Text files", "*.txt")])
        
        if not file_path:
            return
        
        with open(file_path, "r", encoding="utf-8") as file:
            expression = file.read().strip()
        
        self.entry_expression.delete(0, tk.END)
        self.entry_expression.insert(0, expression)
        self.result_text.delete(1.0, tk.END)

    def _save_expr_result(self) -> None:
        expression = self.entry_expression.get().strip()

        if not expression:
            messagebox.showerror("Error", "No Expression")
            return
        
        result = self.result_text.get("1.0", tk.END)
        if not result.strip():
            self._check_expression()
            result = self.result_text.get("1.0", tk.END)
        
        output = expression + "\n" + result
        
        file_path = filedialog.asksaveasfilename(
            title="Enter File Name",
            initialfile="result.txt",
            filetypes=[("Text files", "*.txt")])
        
        if not file_path:
            return
        
        try:
            with open(file_path, "w", encoding="utf-8") as file:
                file.write(output)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to save file:\n{e}")

    def build_ui(self) -> None:
        text_frame = ttk.Frame(self, padding=10)
        ttk.Label(text_frame, text="Expression:").pack()
        self.entry_expression = ttk.Entry(text_frame, width=80)
        self.entry_expression.pack()

        ttk.Label(text_frame, text="Result:").pack()
        self.result_text = tk.Text(text_frame, height=12, wrap="word")
        self.result_text.pack()
        text_frame.pack()

        buttons_frame = ttk.Frame(self, padding=10)
        buttons_padx = 5
        ttk.Button(buttons_frame, text="Read Expression From File", command=self._read_expr_from_file).grid(row=0, column=0, padx=buttons_padx)
        ttk.Button(buttons_frame, text="Save Expression Result To File", command=self._save_expr_result).grid(row=0, column=1, padx=buttons_padx)
        ttk.Button(buttons_frame, text="Check Expression", command=self._check_expression).grid(row=0, column=2, padx=buttons_padx)
        buttons_frame.pack()

    def _check_expression(self) -> None:
        expression = self.entry_expression.get().strip()
        self.result_text.delete(1.0, tk.END)

        if not expression:
            messagebox.showwarning("Warning", "Enter or Read an expression from file.")
            return
        
        result = self.checker.check_expression(expression)
        if result is None:
            self.result_text.insert(tk.END, "Not Balanced.")
        else:
            self.result_text.insert(tk.END, "Balanced.\nPairs:\n")
            for open_pos, close_pos in result:
                self.result_text.insert(tk.END, f"({open_pos},{close_pos})\n")

if __name__ == "__main__":
    app = App()
    app.mainloop()


            
        

