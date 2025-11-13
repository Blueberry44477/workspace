import tkinter as tk
from tkinter import ttk, messagebox
import random
from typing import Optional, Any

class Node:
    def __init__(self, data: Any):
        self.data = data
        self.next = None

class CircularList:
    def __init__(self):
        self.head = None

    def append(self, data):
        node = Node(data)

        if not self.head:
            self.head = node
            node.next = node
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = node
            node.next = self.head
    
    def __iter__(self):
        temp = self.head
        if not temp:
            return
        yield temp.data
        temp = temp.next
        while temp != self.head:
            yield temp.data
            temp = temp.next

    def get_every_nth(self, n: int) -> list:
        if not self.head:
            return []
        
        result = []
        temp = self.head
        count = 1
        seen = set()
        while temp not in seen:
            if count % n == 0:
                result.append(temp.data)
            seen.add(temp)
            temp = temp.next
            count += 1
        return result


class App:
    def __init__(self, root):
        self.font = ("Arial", 16)

        self.root = root
        self.root.title("Task 2")

        self.build_widgets()
        self.root.mainloop()

    def build_widgets(self) -> None:
        columns = ("#", "Team 1 Player", "Team 2 Player")
        self.table = ttk.Treeview(self.root, columns = columns, show = "headings", height = 10)
        for column in columns:
            self.table.heading(column, text = column)
            self.table.column(column, anchor="center", width = 160)
        self.table.pack(fill="x", pady=5)
        
        ttk.Button(self.root, text="Define Teams", command=self.define_teams).pack()
        
    def load_team(self, filename: str) -> CircularList:
        team = CircularList()
        with open(filename, 'r', encoding='utf-8') as file:
            for line in file:
                name = line.strip()
                if name:
                    team.append(name)
        return team

    def create_match_table(self, team1: CircularList, team2: CircularList) -> tuple:
        n = random.randint(2, 5)
        m = random.randint(2, 5)

        players1 = team1.get_every_nth(n)
        players2 = team2.get_every_nth(m)

        matches = list(zip(players1, players2))

        return n, m, matches
    
    def define_teams(self) -> None:
        try:
            team1 = self.load_team("team1.txt")
            team2 = self.load_team("team2.txt")
        except FileNotFoundError:
            messagebox.showerror("Error", "No file team1.txt or team2.txt")
            return
        
        n, m, matches = self.create_match_table(team1, team2)
        
        # Clear Table
        for row in self.table.get_children():
            self.table.delete(row)

        # Update Table Data
        for i, (a, b) in enumerate(matches, 1):
            self.table.insert("", tk.END, values=(i, a, b))
        
        self.write_teams_to_file("result.txt", matches, n, m)

    def write_teams_to_file(self, filename: str, matches: CircularList, n: int, m: int) -> None:
        with open(filename, "w", encoding="utf-8") as file:
            file.write(f"Teams (n={n}, m={m})\n")
            for i, (a, b) in enumerate(matches, 1):
                file.write(f"{i}. {a} vs {b}\n")
        messagebox.showinfo("Result", f"Result is stored in result.txt")



def main():
    root = tk.Tk()
    app = App(root)

if __name__ == "__main__":
    main()
