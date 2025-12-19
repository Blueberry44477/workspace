import pandas as pd
import matplotlib.pyplot as plt

# Data Frame: A 2D labeled data structure 
df = pd.read_csv("track_data_final.csv")
df.head()
df.tail()
df.info()

print(df.shape)
print(df.columns)

# Data Types
print(df.dtypes)

print("Data Frame Indexation")
# First Row
print(df.loc[0])
# label-based indexing
print(f"\nlabel-based indexing\n{df.loc[0, "artist_name"]}")
# position-based indexing
print(f"\n{df.iloc[3]}")

print(f"\nDescribe:\n{df.describe()}")

print(f"\nvalue_counts:\n{df["artist_popularity"].value_counts()}")
print(f"\nvalue_counts:\n{df["artist_popularity"].value_counts(normalize=True)}") # Percents

# Unique value
print(f"\nunique:\n{df["artist_popularity"].unique()}")
print(f"\nunique:\n{df["artist_popularity"].nunique()}")

print(f"\ncorr:\n{df.corr(numeric_only=True)}")

print(f"\ncorr:\n{df.sample(10)}") # 10 random
print(f"\ncorr:\n{df.sample(frac=0.1)}") # 10 percent of DataFrame
