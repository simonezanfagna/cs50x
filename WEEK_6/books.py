books = []

for i in range(3):
    book = dict()
    book["author"] = input("Author: ")
    book["title"] = input("Title: ")
    books.append(book)


for b in books:
    print(f"Author: {b['author']}, Title: {b['title']}")
