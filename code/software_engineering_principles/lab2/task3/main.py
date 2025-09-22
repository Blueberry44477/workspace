import random

class Train:
    def __init__(self, num_cars=10, num_seats=20):
        self.num_cars = num_cars
        self.num_seats = num_seats
        self.cars = [[random.randint(0, 1) for _ in range(num_seats)] for _ in range(num_cars)]

    def print_train(self):
        print("(нижні: _, верхні: ^, зайняті: X):")
        for i, car in enumerate(self.cars):
            row_visual = []
            for idx, seat in enumerate(car):
                if seat == 1:
                    row_visual.append(" X ")
                else:
                    # нижні місця непарні
                    row_visual.append(" _ " if idx % 2 == 0 else " ^ ")
            print(f"Вагон {i+1:2}: {''.join(row_visual)}")
            
    # чи має вагон вільні місця
    def has_free_lower_seats(self, car_number):
        if not (1 <= car_number <= self.num_cars):
            raise ValueError("Номер вагону поза діапазоном")
        
        car = self.cars[car_number - 1]
        lower_seats = car[0::2]
        return 0 in lower_seats # повертаємо true якщо є вільні місця

    def get_free_lower_seats(self, car_number):
        car = self.cars[car_number - 1]
        return [i for i in range(0, self.num_seats, 2) if car[i] == 0]
        
def main():
    train = Train()

    train.print_train()

    while True:
        try:
            car_num = int(input("Введіть номер вагону (1-10): "))
            if 1 <= car_num <= train.num_cars:
                break
            print("Некоректний номер вагону.")
        except ValueError:
            print("Введіть число від 1 до 10.")

    if train.has_free_lower_seats(car_num):
        free_seats = train.get_free_lower_seats(car_num)
        print(f"У вагоні {car_num} є вільні нижні місця: {free_seats}")
    else:
        print(f"У вагоні {car_num} вільних нижніх місць немає.")

if __name__ == "__main__":
    main()
