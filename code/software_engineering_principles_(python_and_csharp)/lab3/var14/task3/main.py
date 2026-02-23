import tkinter as tk
from tkinter import messagebox
import re

class App:
    def __init__(self):
        self.font = ("Arial, 18")

        self.root = tk.Tk()
        self.root.title("Lexographic Remover")
        self.build_widgets()
        self.root.mainloop()

    def build_widgets(self):
        tk.Label(self.root, text="Input:", font=self.font).pack(anchor="nw", padx=10, pady=5)

        self.input_box = tk.Text(self.root, wrap="word", height=5, width=100, font=self.font)
        self.input_box.insert("1.0", "abc car box ab buzz ace zoo")
        self.input_box.pack(anchor="nw", padx=10, pady=5)

        tk.Label(self.root, text="Output:", font=self.font).pack(anchor="nw", padx=10, pady=5)

        self.output_box = tk.Text(self.root, wrap="word", height=5, width=100, font=self.font)
        self.output_box.pack(anchor="nw", padx=10, pady=5)

        self.button = tk.Button(self.root, text="Remove Lexographic Words", command = self.remove, font=self.font)
        self.button.pack(anchor="nw", padx=10, pady=5)

    def is_lex_order(self, word: str) -> bool:
        word = re.sub(r'[^A-Za-zА-Яа-я]', '', word)  # Leave only letters
        return all(word[i] <= word[i+1] for i in range(len(word)-1))

    def remove(self):
        text = self.input_box.get("1.0", tk.END).strip()
        if not text:
            messagebox.showinfo("Info", "Input is empty.")
            return

        words = re.findall(r'\b\w+\b|\S', text)

        new_words = []
        for w in words:
            if re.match(r'\w+', w) and self.is_lex_order(w):
                continue 
            new_words.append(w)

        result = ' '.join(new_words)
        result = re.sub(r'\s+([.,;!?])', r'\1', result)

        self.output_box.delete("1.0", tk.END)
        self.output_box.insert("1.0", result)

def main():
    App()

if __name__ == "__main__":
    main()