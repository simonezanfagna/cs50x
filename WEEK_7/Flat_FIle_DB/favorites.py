# CON LA LIBRERIA collections
import csv
from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = Counter()

    for row in reader:

        favorite = row["language"]
        counts[favorite] += 1

favoriteInput = input("Favorite: ")
print(f"{favoriteInput}: {counts[favoriteInput]}")

for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")


# SENZA LA LIBRERIA collections
"""
import csv

with open("favorites.csv","r") as file:
    reader = csv.DictReader(file)

    counts = {}

    for row in reader:

        favorite = row["language"]

        if favorite in counts:
            counts[favorite] = counts[favorite] + 1
        else:
            counts[favorite] = 1

for favorite in sorted(counts, key = counts.get, reverse = True):
    print(f"{favorite}: {counts[favorite]}")

 """
