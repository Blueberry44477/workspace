import tkinter as tk
from collections import namedtuple
from tkinter import messagebox

def get_salary(employee, salary_monthly, bonus):
    avg_salary = sum(salary_monthly) / len(salary_monthly)
    salary_vacation = 0.85 * avg_salary + 0.95 * bonus
    return f"Employee {employee} – your vacation profit for the six months are: {salary_vacation}"

class App:
    def __init__(self, root):
        self.font = ("Arial", 18)

        self.root = root
        self.root.title("Task 2")
        self.build_widgets()

    def build_widgets(self):
        frame = tk.Frame(self.root)

        tk.Label(frame, text="Worker Surname:", padx=5, pady=5, font=self.font).grid(row=0, column=0, sticky="w")
        self.surname_entry = tk.Entry(frame, font=self.font)
        self.surname_entry.grid(row=0, column=1)

        tk.Label(frame, text="Last 6 Salaries:", padx=5, pady=5, font=self.font).grid(row=1, column=0, sticky="w")
        self.salaries_entry = tk.Entry(frame, font=self.font)
        self.salaries_entry.grid(row=1, column=1)
        
        tk.Label(frame, text="Bonus:", padx=5, pady=5, font=self.font).grid(row=2, column=0, sticky="w")
        self.bonus_entry = tk.Entry(frame, font=self.font)
        self.bonus_entry.grid(row=2, column=1)

        self.result_label = tk.Label(frame, text="", font=self.font, background="white")
        self.result_label.grid(row=3, column=0, columnspan=2, sticky="ew")

        tk.Button(frame, text="Calculate", command=self.calculate, font=self.font).grid(row=4, column=0, columnspan=2, pady=10)
        
        frame.pack()

    def calculate(self):
        worker = self.surname_entry.get().strip()

        try:
            salaries = [float(x) for x in self.salaries_entry.get().split()]
            if len(salaries) != 6:
                raise ValueError("Must be 6 Salaries")
            bonus = float(self.bonus_entry.get())
            
            Salaries = namedtuple("Salaries", ['m1', 'm2', 'm3', 'm4', 'm5', 'm6'])
            salaries_monthly = Salaries(*salaries)

            result = get_salary(worker, salaries_monthly, bonus)
            self.result_label.config(text=result)
        except ValueError as error:
            messagebox.showerror("Error", str(error))


def main():
    root = tk.Tk()
    app = App(root)
    root.mainloop()

if __name__ == "__main__":
    main()