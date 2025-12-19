import pandas as pd
import matplotlib.pyplot as plt

url = "https://raw.githubusercontent.com/uiuc-cse/data-fa14/gh-pages/data/iris.csv"
df = pd.read_csv(url)

print("Виведіть загальну інформацію про зазначену базу даних.")
print(df.info())

print("Виведіть перші 5 записів")
print(df.head())

print("\nВиведіть останні 10 записів.")
print(df.tail(10))

print("Порахувати середнє значення кожного параметра (sepal/petal length/width) по кожному виду (species).")
grouped = df.groupby("species").agg({
    "sepal_length": "mean",
    "sepal_width": "mean",
    "petal_length": "mean",
    "petal_width": "mean"
})
print(grouped)

print("Побудувати групований bar chart: вид рослини — по осі X, середні значення — по Y")
grouped.plot(kind="bar", figsize=(10, 6))
plt.title("Середні параметри квітів Iris за видами")
plt.xlabel("Вид")
plt.ylabel("Сер. значення")
plt.xticks(rotation=0)
plt.tight_layout()
plt.show()
