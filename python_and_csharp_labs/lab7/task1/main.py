import re
import tkinter as tk
from tkinter import messagebox
from datetime import datetime, timedelta

DATE_RE = re.compile(r'^[0-3]\d[0-1]\d\d{4}$')  # DDMMYYYY
TIME_RE = re.compile(r'^[0-2]\d:[0-5]\d:[0-5]\d$')  # HH:MM:SS

def parse_inputs(date_str: str, time_str: str):
    if not DATE_RE.match(date_str):
        raise ValueError("Wrong Date Format. Use DDMMYYYY.")
    if not TIME_RE.match(time_str):
        raise ValueError("Wrong Time Format. Use HH:MM:SS.")

    day = int(date_str[0:2])
    month = int(date_str[2:4])
    year = int(date_str[4:8])
    hour, minute, second = map(int, time_str.split(':'))

    try:
        return datetime(year, month, day, hour, minute, second)
    except Exception as e:
        raise ValueError(f"Error: {e}")


def compute_message(appointment: datetime, now: datetime):
    delta: timedelta = appointment - now
    hours = delta.total_seconds() / 3600.0
    hours_rounded = round(hours, 2)

    if hours > 0:
        when_str = f"Left {hours_rounded} hours."
    elif abs(hours) < 1e-9:
        when_str = "Appointment is now."
    else:
        when_str = f"Already past {abs(hours_rounded)} hours."

    part = "First half of the day." if appointment.hour < 12 else "Second part of the day."
    return when_str, part

class App:
    def __init__(self, root):
        self.root = root
        root.title("Task 1")
        root.resizable(False, False)
        self.padding = 8
        self.build_widgets()

    def build_widgets(self):
        tk.Label(self.root, text="Enter date and time for doctor reception.").pack()

        frm = tk.Frame(self.root, padx=self.padding, pady=self.padding)

        tk.Label(frm, text="Date (DDMMYYYY):").grid(row=0, column=0, sticky="e")
        self.date_entry = tk.Entry(frm, width=8)
        self.date_entry.grid(row=0, column=1, padx=self.padding, pady=4)
        self.date_entry.insert(0, datetime.now().strftime("%d%m%Y"))

        tk.Label(frm, text="Time (HH:MM:SS):").grid(row=1, column=0, sticky="e")
        self.time_entry = tk.Entry(frm, width=10)
        self.time_entry.grid(row=1, column=1, padx=self.padding, pady=4)
        self.time_entry.insert(0, datetime.now().strftime("%H:%M:%S"))

        calc_btn = tk.Button(frm, text="Calculate", command=self.calculate)
        calc_btn.grid(row=2, column=0, columnspan=2, pady=(6, 4))

        self.result_label = tk.Label(frm, text="", justify="left", anchor="w")
        self.result_label.grid(row=3, column=0, columnspan=2, sticky="w", pady=(6, 0))
        
        frm.pack()

    def calculate(self):
        date_str = self.date_entry.get().strip()
        time_str = self.time_entry.get().strip()
        try:
            appt = parse_inputs(date_str, time_str)
            now = datetime.now()
            when_str, part = compute_message(appt, now)
            text = f"Assigned: {appt}\n{when_str}\nPart of the Day: {part}"
            self.result_label.config(text=text)
        except ValueError as e:
            messagebox.showerror("Input Error", str(e))
        except Exception as e:
            messagebox.showerror("Error", str(e))


def main():
    root = tk.Tk()
    App(root)
    root.mainloop()


if __name__ == "__main__":
    main()
