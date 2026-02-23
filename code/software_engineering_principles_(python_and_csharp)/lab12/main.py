from typing import Iterable, Callable

# 1
def sort_by_age(people: list[dict]) -> list[dict]:     
    return sorted(people, key=lambda person: person["age"])

# 2
def filter_long_words(words: list[str]) -> list[str]:
    return list(filter(lambda word: len(word) > 3, words))

# 3
def capitalize_words(words: Iterable[str]) -> Iterable[str]:
    return map(str.capitalize, words)

# 4
def has_uppercase(password: str) -> bool:
    return any(symbol.isupper() for symbol in password)

def has_digit(password: str) -> bool:
    return any(symbol.isdigit() for symbol in password)

def is_long_enough(password: str) -> bool:
    return True if len(password) >= 8 else False

def has_special_char(password: str) -> bool:
    special_chars = "!@#$%^&*()."
    return any(char in special_chars for char in password)

def no_spaces(password: str) -> bool:
    return " " not in password


def validate_password(password: str) -> bool:
    rules: list[Callable[[str], bool]] = {
        has_uppercase,
        has_digit,
        is_long_enough,
        has_special_char,
        no_spaces
    }
    return all(rule(password) for rule in rules)

def main():
    # 1
    print(sort_by_age([{"name": "Alice", "age": 30},
                       {"name": "Bob", "age": 25},
                       {"name": "Eve", "age": 35}])) 
    
    # 2
    print(filter_long_words(["a", "the", "code", "Python", "is", "fun"]))
    
    # 3
    print(list(capitalize_words(["python", "java", "c++"])))

    # 4
    print(validate_password("StrongPass1!")) #True
    print(validate_password("weakpass")) #False
    print(validate_password("Short7!")) #False
    print(validate_password("With Space1!")) #False
    print(validate_password("NoSpecialChar1")) #False

if __name__ == "__main__":
    main()