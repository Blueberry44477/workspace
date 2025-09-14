import random
"""
Використати циклічний оператор, на вибір студента.
Написати програму, яка реалізовує умову «Серія пострілів по мішені» (мішень – це
заштрихована область із завдання 1.1).
Використовуючи генератор псевдовипадкових послідовностей чисел задати
координати десяти пострілів (x, y).
Обчислити чи відбулось попадання в мішень та вивести у вигляді таблиці результати
пострілів по мішені.
Перевірку потрапляння пострілу у мішень та генерування координат пострілів
реалізувати у вигляді підпрограм (функцій).
"""
def is_in_target(x: float, y: float):
    # Верхня права
    if 0 <= x <= 2**0.5 and 0 <= y <= 1:
        if y == x or y == -x**2 + 2:
            return "На межі"
        elif y < x and y < -x**2 + 2:
            return "В області"
    # Нижня ліва
    elif -2 <= x <= 0 and -2 <= y <= 0:
        if y == x or y == -x**2 + 2:
            return "На межі"
        elif y > x and y < -x**2 + 2:
            return "В області"
    return "Не в області"

def generate_shots(n: int, 
                   x_min: int = -2, x_max: int = 2**0.5,
                   y_min: int = -2, y_max: int = 2,
                   precision: int = 2):
    shots = []
    for _ in range(n):
        x = round(random.uniform(x_min, x_max), precision)
        y = round(random.uniform(y_min, y_max), precision)
        shots.append((x, y))
    return shots

def main():
    x = -0.5
    y = 1.0
    print(is_in_target(x,y))

    shots = generate_shots(10)
    print(f"{'№':<5}{'x':<10}{'y':<10}{'Попадання'}")
    print("-" * 35)

    for i, (x, y) in enumerate(shots, start = 1):
        print(f"{i:<5}{x:<10.2f}{y:<10.2f}{is_in_target(x,y)}")

if __name__ == "__main__":
    main()
