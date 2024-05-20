def get_PositiveInt(prompt):
    while True:
        try:
            intValue = int(input(prompt))
            if intValue > 0:
                return intValue
            else:
                print("Please enter a positive integer!")
        except ValueError:
            print("Not an integer!")


def main():
    height = get_PositiveInt("Height: ")

    for i in range(height):
        print("#" * height)


main()
