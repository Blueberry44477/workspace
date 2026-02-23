from typing import Iterator

# Task 1
# def filter_even_numbers(nums: list[int]) -> list[int]:
#     result = []
#     for num in nums:
#         if num % 2 == 0:
#         result.append(num)
#     return result

def filter_even_numbers(nums: list[int]) -> list[int]:
    return[num for num in nums if num % 2 == 0]

# Task 2
class Countdown:
    def __init__(self, start: int):
        if start <= 0:
            raise ValueError("Start number must be larger than 0")
        self.start = start

    def __iter__(self):
        self.num = self.start
        return self
    
    def __next__(self):
        if self.num < 0:
            raise StopIteration
        current = self.num
        self.num -= 1
        return current
    
# Task 3
def float_range(start: float, stop: float, step: float) -> Iterator[float]:
    if step == 0:
        raise ValueError("Step cannot be 0")
    current = start
    if step > 0:
        while current < stop:
            yield round(current, 10)
            current += step
    else:
        while current > stop:
            yield round(current, 10)
            current -= step

# Task 4
def walk_tree(data: dict) -> Iterator[str]:
    for key, value in data.items():
        yield key
        if isinstance(value, dict):
            yield from walk_tree(value)
    
def main():
    # Task 1
    numbers = [1,2,3,4,5,6,7,8,9,10]
    print(filter_even_numbers(numbers))

    # Task 2
    countdown = Countdown(10)
    for count in countdown:
        print(count)

    print(list(Countdown(10)))

    # Task 3
    print(list(float_range(1.0, 5.0, 0.1)))

    # Task 4
    tree = {"a": {"b": {"c": 1}}, "d": 2}
    print(list(walk_tree(tree)))

if __name__ == "__main__":
    main()
