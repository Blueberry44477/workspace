import tkinter as tk
from tkinter import messagebox

class App:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("App")
        self.build_menubar()
        self.build_widgets()
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.root.mainloop()
    
    def build_widgets(self):
        self.label = tk.Label(self.root, text="Your Message")
        self.label.pack(padx=10, pady=10)

        self.textbox = tk.Text(self.root)
        self.textbox.bind("<KeyPress>", self.shortcut)
        self.textbox.pack(padx=10, pady=10)

        self.checkbut_state = tk.IntVar()
        self.checkbut = tk.Checkbutton(self.root, variable=self.checkbut_state, text = "Show Messagebox")
        self.checkbut.pack(padx=10, pady=10)

        self.button = tk.Button(self.root, text="Show Message", command=self.show_message)
        self.button.pack(padx=10, pady=10)

        self.clearbtn = tk.Button(self.root, text="Clear Textbox", command=self.clear_textbox)
        self.clearbtn.pack(padx=10, pady=10)
    
    def build_menubar(self):
        self.menubar = tk.Menu(self.root)

        self.file_menu = tk.Menu(self.menubar, tearoff=0)
        self.file_menu.add_command(label="Close", command=self.on_closing)
        self.file_menu.add_separator()
        self.file_menu.add_command(label="Close Without Question", command=exit)

        self.action_menu = tk.Menu(self.menubar, tearoff=0)
        self.action_menu.add_command(label="Show Message", command=self.show_message)

        self.menubar.add_cascade(menu=self.file_menu, label="File")
        self.menubar.add_cascade(menu=self.action_menu, label="Action")
        self.root.config(menu=self.menubar)
    
    def show_message(self):
        if self.checkbut_state.get() == 0:
            print(self.textbox.get("1.0", tk.END))
        else:
            messagebox.showinfo(title="Message", message=self.textbox.get("1.0", tk.END))

    def clear_textbox(self):
        self.textbox.delete("1.0", tk.END)

    def shortcut(self, event):
        # print(event.keysym)
        # print(event.state)
        if event.state == 4 and event.keysym == "Return":
            self.show_message()

    def on_closing(self):
        if messagebox.askyesno(title="Quit?", message="Do you really want to quit?"):
            self.root.destroy()

def main():
    App()

if __name__ == "__main__":
    main()



