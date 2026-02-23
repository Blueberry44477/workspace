import tkinter as tk
from tkinter import messagebox

class State:
    def __init__(self, name="", population=0, area=0):
        self.name = name
        self.population = population
        self.area = area

    @classmethod
    def from_parameters(cls, name, population, area):
        return cls(name, population, area)

    def show(self):
        return f"State: {self.name}\nPopulation: {self.population}\nArea: {self.area}"

    def __del__(self):
        print("Лабораторна робота виконанна студентом 2 курсу - Скубач Віталій Олексійович.")


class Republic(State):
    def __init__(self, name="", population=0, area=0, president=""):
        super().__init__(name, population, area)
        self.president = president
        self.type = "Democratic"

    def show(self):
        base = super().show()
        return f"{base}\nType: {self.type}\nPresident: {self.president}"


class Monarchy(State):
    def __init__(self, name="", population=0, area=0, monarch=""):
        super().__init__(name, population, area)
        self.monarch = monarch

    def show(self):
        base = super().show()
        return f"{base}\nMonarch: {self.monarch}"


class Kingdom(Monarchy):
    def __init__(self, name="", population=0, area=0, monarch="", dynasty=""):
        super().__init__(name, population, area, monarch)
        self.dynasty = dynasty

    def show(self):
        base = super().show()
        return f"{base}\nDynasty: {self.dynasty}"


class Country(State):
    def __init__(self, name="", population=0, area=0, leader=""):
        super().__init__(name, population, area)
        self.leader = leader

    def show(self):
        base = super().show()
        return f"{base}\nLeader: {self.leader}"
    
class App:
    def __init__(self, root):
        self.font = ("Arial", 18)
        
        self.root = root
        self.root.title("Task 2")

        self.build_widgets()
        self.root.mainloop()
    
    def build_widgets(self):
        grid_padding = 5

        tk.Label(self.root, text="Choose type of state:", font=self.font).grid(row=0, column=0, sticky="w", pady=grid_padding)
        self.option = tk.StringVar(value="Republic")
        self.government_option_menu = tk.OptionMenu(self.root, self.option, "Republic", "Monarchy", "Kingdom", "Country")
        self.government_option_menu.config(font=self.font)
        self.government_option_menu.grid(row=0, column=1, pady=grid_padding)


        tk.Label(self.root, text="Name:", font=self.font).grid(row=1, column=0, sticky="w", pady=grid_padding)
        self.name_entry = tk.Entry(self.root)
        self.name_entry.config(font=self.font)
        self.name_entry.grid(row=1, column=1, pady=grid_padding)

        tk.Label(self.root, text="Population:", font=self.font).grid(row=2, column=0, sticky="w", pady=grid_padding)
        self.population_entry = tk.Entry(self.root)
        self.population_entry.config(font=self.font)
        self.population_entry.grid(row=2, column=1, pady=grid_padding)

        tk.Label(self.root, text="Area:", font=self.font).grid(row=3, column=0, sticky="w", pady=grid_padding)
        self.area_entry = tk.Entry(self.root)
        self.area_entry.config(font=self.font)
        self.area_entry.grid(row=3, column=1, pady=grid_padding)

        tk.Label(self.root, text="Leader/President/Monarch:", font=self.font).grid(row=4, column=0, sticky="w", pady=grid_padding)
        self.leader_entry = tk.Entry(self.root)
        self.leader_entry.config(font=self.font)
        self.leader_entry.grid(row=4, column=1, pady=grid_padding)

        tk.Button(self.root, text="Show Info", command=self.show_info, font=self.font).grid(row=5, column=0, columnspan=2, pady=10)
        
    def show_info(self):
        name = self.name_entry.get() or ""
        population = int(self.population_entry.get() or 0)
        area = int(self.area_entry.get() or 0)
        leader = self.leader_entry.get() or ""

        state_type = self.option.get()
        if state_type == "Republic":
            obj = Republic(name, population, area, leader)
        elif state_type == "Monarchy":
            obj = Monarchy(name, population, area, leader)
        elif state_type == "Kingdom":
            obj = Kingdom(name, population, area, leader)
        else:
            obj = Country(name, population, area, leader)

        messagebox.showinfo("State Info", obj.show())

def main():
    root = tk.Tk()
    app = App(root)
    
if __name__ == "__main__":
    main()