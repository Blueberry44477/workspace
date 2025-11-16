import tkinter as tk
from tkinter import ttk, messagebox
from trees.gentree import GenTree
    
class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Task 1")
        self.tree = GenTree()
        self.build_ui()

    def build_ui(self) -> None:
        frame = ttk.Frame(self, padding=10)
        frame.grid(row=0, column=0, sticky="nsew")

        ttk.Label(frame, text="Route:").grid(row=0, column=0, sticky="w")
        self.entry_new = ttk.Entry(frame, width=30)
        self.entry_new.grid(row=0, column=1)

        ttk.Label(frame, text="Father Route:").grid(row=1, column=0, sticky="w")
        self.entry_parent = ttk.Entry(frame, width=30)
        self.entry_parent.grid(row=1, column=1)

        ttk.Button(frame, text="Add Route", command=self.add_route).grid(row=2, column=0, pady=5)
        ttk.Button(frame, text="Delete Route", command=self.delete_route).grid(row=2, column=1, pady=5)
        ttk.Button(frame, text="Update Route", command=self.refresh_treeview).grid(row=2, column=2, pady=5)

        self.treeview = ttk.Treeview(frame)
        self.treeview.grid(row=3, column=0, columnspan=3, pady=10, sticky="nsew")

        scrollbar = ttk.Scrollbar(frame, orient="vertical", command=self.treeview.yview)
        self.treeview.configure(yscrollcommand=scrollbar.set)
        scrollbar.grid(row=3, column=3, sticky="ns")

        frame.rowconfigure(3, weight=1)
        frame.columnconfigure(1, weight=1)

    def add_route(self) -> None:
        new = self.entry_new.get().strip()
        parent = self.entry_parent.get().strip()

        if not new:
            messagebox.showerror("Error", "Enter Route Name.")
            return
        
        result = self.tree.insert(parent, new) if parent else self.tree.insert(None, new)

        if result:
            self.refresh_treeview()
        else:
            messagebox.showerror("Error", "No Parent Route Found")

    def delete_route(self):
        route_name = self.entry_new.get().strip()
        if not route_name:
            messagebox.showerror("Error", "Enter Route Name.")
            return

        result = self.tree.delete(route_name)
        if result:
            self.refresh_treeview()
        else:
            messagebox.showerror("Error", "No Route Found.")

    def refresh_treeview(self) -> None:
        self.treeview.delete(*self.treeview.get_children())

        if not self.tree.root:
            return

        self.insert_recursive("", self.tree.root)
    
    def insert_recursive(self, parent_id, node):
        current_id = self.treeview.insert(parent_id, "end", text=node.data)
        for child in node.children:
            self.insert_recursive(current_id, child)

def main():
    app = App()
    app.mainloop()

if __name__ == "__main__":
    main()





