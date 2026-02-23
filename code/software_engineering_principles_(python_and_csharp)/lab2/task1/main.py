def sum_between_min_max(arr) -> int:
    if not arr:
        return 0
    
    min_index = arr.index(min(arr))
    max_index = arr.index(max(arr))

    start, end = sorted([min_index, max_index])
    # arr[min_index:max_index+1] зріз працює лише якщо min_index < max_index.
    return sum(arr[start:end+1])

def main():
    arr = list(map(int, input("Введіть елементи через пробіл: ").split()))
    print(arr)
    sum = sum_between_min_max(arr)
    print(sum)
    
if __name__ == "__main__":
    main()