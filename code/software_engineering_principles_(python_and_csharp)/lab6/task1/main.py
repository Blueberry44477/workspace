import tkinter as tk
from tkinter import messagebox
from abc import ABC, abstractmethod

current_year = 2025

class Building(ABC):
    def __init__(self, address: str, area: float, year: int):
        self.address = address
        self.area = area
        self.year = year

    @abstractmethod
    def type(self) -> str:
        pass

    @abstractmethod
    def purpose(self) -> str:
        pass
    
    def info(self):
        return (f"Adress: {self.address}\n"
                f"Area: {self.area}\n"
                f"Year: {self.year}")
    
    def age(self):
        return current_year - self.year

class Shed(Building):
    def __init__(self, address: str, area: float, year: int, material: str):
        super().__init__(address, area, year)
        self.material = material
    
    def type(self) -> str:
        return "Shed"
    
    def purpose(self) -> str:
        return "Item Storage"
    
    def info(self):
        base_info = super().info()
        return (f"{base_info}\n"
                f"Type: {self.type()}\n"
                f"Material: {self.material}")
    
    def durability(self) -> str:
        if self.material.lower() == "wood" and self.age() > 15:
            return "Requires maintenance (check for rot)."
        elif self.material.lower() == "metal" and self.age() > 25:
            return "Requires rust inspection."
        else:
            return "Durability appears adequate."

class Shelter(Building):
    def __init__(self, address: str, area: float, year: int, protection: int):
        super().__init__(address, area, year)
        self.protection = protection
    
    def type(self) -> str:
        return "Shelter"
    
    def purpose(self) -> str:
        return "Protecton against nuclear impact"
    
    def info(self) -> str:
        base_info = super().info()
        return (f"{base_info}\n"
                f"Type: {self.type()}\n"
                f"Protection against impact (tons): {self.protection}")
    
    def calculate_capacity(self, required_area_per_person: float = 1.5) -> int:
        return int(self.area / required_area_per_person)
    
buildings = [Shed("Zaporizka 5", 100, 1994, "wood"),
             Shelter("Zaporizka 5", 100, 1994, 150)]

class App:
    def __init__(self, root):
        self.root = root
        root.title("Task 1")
        root.geometry("800x600")
        self.build_widgets()

    def build_widgets(self):
        tk.Label(self.root, text="Building Type:").grid(row=0, column=0, sticky="w", padx=5, pady=5)
        self.type = tk.StringVar(value="Shed")
        tk.OptionMenu(self.root, self.type, "Shed", "Shelter").grid(row=0, column=1, padx=5, pady=5)

        self.entries = {}
        params = [("Address", "address"),
                  ("Area", "area"),
                  ("Year", "year"),
                  ("Material (for shed)", "material"),
                  ("Protection against impact (tons)", "protection")]
        
        for i, (label_text, key) in enumerate(params, start=1):
            tk.Label(self.root, text=label_text).grid(row=i, column=0, sticky="w", padx=5, pady=2)

            entry = tk.Entry(self.root)
            entry.grid(row=i, column=1, padx=5, pady=2)
        
            self.entries[key] = entry

        tk.Button(self.root, text="Add Building", command=self.add_building).grid(row=len(params)+1, column=0, columnspan=2, pady=10)
        
        # Street Search
        tk.Label(self.root, text="Street Search").grid(row=len(params)+2, column=0, sticky="w", padx=5, pady=2)
        self.street_input = tk.Entry(self.root)
        self.street_input.grid(row=len(params)+2, column=1)

        tk.Button(self.root, text="Show Buildings on Selected Street", command=self.search_buildings).grid(row=len(params)+3, column=0, columnspan=2, pady=10)

        self.output = tk.Text(self.root, width=80, height=30)
        self.output.grid(row=len(params)+4, column=0, columnspan=2, padx=5, pady=5)

        tk.Button(self.root, text="Show All Buildings Info", command=self.display_buildings).grid(row=len(params)+5, column=0, columnspan=2, pady=10)

    def add_building(self):
        try: 
            area = int(self.entries["area"].get())
            year = int(self.entries["year"].get())
        except ValueError:
            messagebox.showerror("Input Error", "Protection (for shelter) Error.")
            return
        
        address = self.entries["address"].get()
        type = self.type.get()

        if type == "Shed":
            material = self.entries["material"].get()
            building = Shed(address, area, year, material)
        elif type == "Shelter":
            try:
                protection = int(self.entries["protection"].get())
            except ValueError:
                messagebox.showerror("Input Error", "Protection (for shelter) Error.")
                return
            building = Shelter(address, area, year, protection)
        
        buildings.append(building)
        messagebox.showinfo("Success", f"{type} has been added.")
        self.output.delete(1.0, tk.END)
        self.output.insert(1.0, building.info())
        
    def show_info(self, buildings_list: list, title: str):
        self.output.delete(1.0, tk.END) 
        self.output.insert(tk.END, f"--- {title} {len(buildings_list)}\n")

        if not buildings_list:
            self.output.insert(tk.END, "Nothing found.")
            return

        for i, building in enumerate(buildings_list):
            info = building.info()
            self.output.insert(tk.END, f"{i+1}. {info}\n----------\n")
    
    def display_buildings(self):
        self.show_info(buildings, "Buildings:")

    def search_buildings(self):
        search_street = self.street_input.get().strip()

        if not search_street:
            messagebox.showerror("Error", "Please Enter Street Name.")
            return

        found_buildings = [
            building for building in buildings
            if search_street.lower() in building.address.lower()
        ]

        self.show_info(found_buildings, f"On street '{search_street}':")

if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()

