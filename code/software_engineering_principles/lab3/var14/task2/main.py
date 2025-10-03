import tkinter as tk
from tkinter import messagebox
import re

class App:
    def __init__(self):
        self.font = ("Arial, 18")

        # Three or six hexadecimal numbers
        self.pattern = r'#(?:[0-9A-Fa-f]{3}|[0-9A-Fa-f]{6})\b'

        self.root = tk.Tk()
        self.root.title("Subtext Finder")
        self.build_widgets()
        self.root.mainloop()

    def build_widgets(self):
        # Input Text
        self.input_label = tk.Label(self.root, text="Input Text:", font=self.font)
        self.input_label.pack(anchor="nw", padx=10, pady=5)

        self.input_box = tk.Text(self.root, wrap="word", height=5, width=100, font=self.font)
        self.input_box.pack(anchor="nw", padx=10, pady=5)
        
        # Output
        self.found_label = tk.Label(self.root, text="Found Subtexts:", font=self.font)
        self.found_label.pack(anchor="nw", padx=10, pady=5)

        self.found_matches = tk.Text(self.root, height=5, width=100, font=self.font)
        self.found_matches.pack(anchor="nw", padx=10, pady=5)

        self.match_count_label = tk.Label(self.root, text="Subtext Count: 0", font=self.font)
        self.match_count_label.pack(anchor="nw", padx=10, pady=5)
        
        self.find_subtext_button = tk.Button(self.root, text="Find Subtexts", command = self.find_matches, font=self.font)
        self.find_subtext_button.pack(anchor="nw", padx=10, pady=5)
        
        # Subtext Remove
        # self.subtext_remove_label = tk.Label(self.root, text="Subtext remove:", font=self.font)
        # self.subtext_remove_label.pack(anchor="nw", padx=10, pady=5)

        # self.input_subtext = tk.Text(self.root, wrap="word", height=2, width=30, font=self.font)
        # self.input_subtext.pack(anchor="nw", padx=10, pady=5)

        self.remove_subtext_button = tk.Button(self.root, text="Remove Subtext", command = self.remove_subtext, font=self.font)
        self.remove_subtext_button.pack(anchor="nw", padx=10, pady=5)
        
        # Subtext Replace
        self.replace_frame = tk.Frame(self.root)

        # tk.Label(self.replace_frame, text="Subtext To Replace:", font=self.font).grid(row=0, column=0)
        # self.replace_input = tk.Text(self.replace_frame, wrap="word", height=2, width=30, font=self.font)
        # self.replace_input.grid(row=0, column=1)

        tk.Label(self.replace_frame, text="Replace With:", font=self.font).grid(row=1, column=0)
        self.replacement_text_input = tk.Text(self.replace_frame, wrap="word", height=2, width=30, font=self.font)
        self.replacement_text_input.grid(row=1, column=1)
        
        self.replace_frame.pack(anchor="nw", padx=10, pady=5)

        self.replace_subtext_button = tk.Button(self.root, text="Replace Subtext", command = self.replace_subtext, font=self.font)
        self.replace_subtext_button.pack(anchor="nw", padx=10, pady=5)
        
    def find_matches(self):
        if not self.pattern:
            messagebox.showerror("No Pattern")
            return
        
        try:
            regex = re.compile(self.pattern)
        except re.error as ex:
            messagebox.showerror("Regex Error")
            return
        
        input_text = self.input_box.get("1.0", tk.END)
        self.matches = []
        for match in regex.finditer(input_text):
            start, end = match.start(), match.end() 
            match_text = match.group(0) # Return text of the match
            self.matches.append((start, end, match_text))
        
        # Update Count Label
        self.match_count_label.config(text=f"Subtext Count: {len(self.matches)}")

        self.found_matches.delete("1.0", tk.END)
        for idx, (_, _, mt) in enumerate(self.matches, start=1):
            self.found_matches.insert(tk.END, f"{idx}: {mt}\n")
        
    def remove_subtext(self):
        # subtext = self.receive_text(self.input_subtext)
        # if not subtext:
        #     return

        # text = self.input_box.get("1.0", tk.END)
        # new_text = text.replace(subtext, "")

        text = self.input_box.get("1.0", tk.END)
        new_text = re.sub(self.pattern, "", text)
        
        self.input_box.delete("1.0", tk.END)
        self.input_box.insert("1.0", new_text)
        
    def replace_subtext(self):
        # subtext = self.receive_text(self.replace_input)
        # if not subtext:
        #     return

        replacement_text = self.replacement_text_input.get("1.0", tk.END).strip()
        if not replacement_text:
            messagebox.showinfo("Info", "Replacement text is empty.")
            return

        text = self.input_box.get("1.0", tk.END)
        new_text = re.sub(self.pattern, replacement_text, text)
        self.input_box.delete("1.0", tk.END)
        self.input_box.insert("1.0", new_text)
        
def main():
    App()

if __name__ == "__main__":
    main()
        