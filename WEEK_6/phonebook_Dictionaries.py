people = [
    {
        "name": "Carter",
        "number": "+1-617-495-1000"
    },
    {
        "name": "David",
        "number": "+1-617-000-1000"
    },
    {
        "name": "John",
        "number": "+1-949-468-2750"
    },
]

name = input("Name: ")

for person in people:
    if person["name"] == name:
        print(f"Found: {person['number']}")
        break
else:
    print("not found")


#
#
#solo con il dictionary
"""
people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John": "+1-949-468-2750",
}

name = get_string("Name: ")
if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")
 """
