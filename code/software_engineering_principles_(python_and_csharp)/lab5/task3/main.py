import tkinter as tk
from tkinter import messagebox

class Computer:
    def __init__(self, clock_speed=0, cores_num=0, ram=0, hdd_capacity=0):
        self.clock_speed = clock_speed
        self.cores_num = cores_num
        self.ram = ram
        self.hdd_capacity = hdd_capacity

    def cost(self):
        return (self.clock_speed * self.cores_num) / 100 + (self.ram / 80) + (self.hdd_capacity / 20)
    
    def suitability(self):
        return (self.clock_speed >= 2000 and
                self.cores_num >= 2 and
                self.ram >= 2048 and
                self.hdd_capacity >= 320)
    
    def info(self):
        info_string = (
            f"Computer Info:\n"
            f"CPU frequency: {self.clock_speed} MHz\n"
            f"Cores: {self.cores_num}\n"
            f"RAM: {self.ram} MB\n"
            f"HDD: {self.hdd_capacity} GB\n"
            f"Cost: {self.cost():.2f}\n"
            f"Suitable: {'Yes' if self.suitability() else 'No'}"
        )
        return info_string
    
class Laptop(Computer):
    def __init__(self, clock_speed=0, cores_num=0, ram=0, hdd_capacity=0, battery_minutes=0):
        super().__init__(clock_speed, cores_num, ram, hdd_capacity)
        self.battery_minutes = battery_minutes

    def cost(self):
        return (super().cost() + self.battery_minutes) / 10

    def suitability(self):
        return self.battery_minutes >= 60

class Tablet(Computer):
    def __init__(self, clock_speed=0, cores_num=0, ram=0, hdd_capacity=0, weight=0):
        super().__init__(clock_speed, cores_num, ram, hdd_capacity)
        self.weight = weight

    def cost(self):
        return super().cost() / 10
    
class Gui:
    def __init__(self, root):
        self.root = root
        root.title("Task 3")
        
        self.build_widgets()
        self.show_default_objects_info()
        self.root.mainloop()

    def build_widgets(self):
        tk.Label(self.root, text="Device type:").grid(row=0, column=0, sticky="w", padx=5, pady=5)
        self.device_type = tk.StringVar(value="Computer")
        tk.OptionMenu(self.root, self.device_type, "Computer", "Laptop", "Tablet").grid(row=0, column=1, padx=5, pady=5)

        self.entries = {}
        params = [("CPU freq (MHz)", "clock_speed"),
                  ("Cores", "cores_num"),
                  ("RAM (MB)", "ram"),
                  ("HDD (GB)", "hdd_capacity"),
                  ("Battery mins (Laptop)", "battery"),
                  ("Weight (Tablet, kg)", "weight")]
        
        for i, (label_text, key) in enumerate(params, start=1):
            tk.Label(self.root, text=label_text).grid(row=i, column=0, sticky="w", padx=5, pady=2)

            entry = tk.Entry(self.root)
            entry.grid(row=i, column=1, padx=5, pady=2)
        
            self.entries[key] = entry

        tk.Button(self.root, text="Show Info", command=self.show_info).grid(row=len(params)+1, column=0, columnspan=2, pady=10)

        self.output = tk.Text(self.root, width=50, height=10)
        self.output.grid(row=len(params)+2, column=0, columnspan=2, padx=5, pady=5)

    def show_info(self):
        try:
            clock_speed = int(self.entries["clock_speed"].get())
            cores_num = int(self.entries["cores_num"].get())
            ram = int(self.entries["ram"].get())
            hdd_capacity = int(self.entries["hdd_capacity"].get())
        except ValueError:
            messagebox.showerror("Input Error", "CPU, Cores, RAM, HDD must be integers")
            return

        device_type = self.device_type.get()
        if device_type == "Computer":
            device = Computer(clock_speed, cores_num, ram, hdd_capacity)

        elif device_type == "Laptop":
            try:
                battery = int(self.entries["battery"].get())
            except ValueError:
                messagebox.showerror("Input Error", "Something is wrong with Battery Minutes.")
                return
            
            device = Laptop(clock_speed, cores_num, ram, hdd_capacity, battery)

        elif device_type == "Tablet":
            try:
                weight = float(self.entries["weight"].get())
            except ValueError:
                messagebox.showerror("Input Error", "Something is wrong with Weight.")
                return
            
            device = Tablet(clock_speed, cores_num, ram, hdd_capacity, weight)

        self.output.delete("1.0", tk.END)
        self.output.insert("1.0", device.info())

    def show_default_objects_info(self):
        """Створення та показ трьох об'єктів у полі виводу GUI при запуску."""
        comp = Computer(clock_speed=2500, cores_num=4, ram=8192, hdd_capacity=512)
        laptop = Laptop(clock_speed=2200, cores_num=4, ram=8192, hdd_capacity=512, battery_minutes=180)
        tablet = Tablet(clock_speed=1800, cores_num=8, ram=4096, hdd_capacity=128, weight=0.8)

        text = (
            "=== Default Objects ===\n\n"
            f"{comp.info()}\n\n"
            f"{laptop.info()}\n\n"
            f"{tablet.info()}\n"
        )

        self.output.delete("1.0", tk.END)
        self.output.insert(tk.END, text)

def main():
    root = tk.Tk()

    computer = Computer()
    laptop = Laptop()
    tablet = Tablet()

    gui = Gui(root)

if __name__ == "__main__":
    main()