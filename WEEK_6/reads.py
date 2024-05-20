import csv

books = []

# CON with NON DEVO CHIUDERE IL FILE, LO FA IN AUTOMATICO
with open("books.csv") as file:
    file_reader = csv.DictReader(file)

    for row in file_reader:
        books.append(row)


for book in books:
    print(f"Author: {book['author']}, Title: {book['title']}")
