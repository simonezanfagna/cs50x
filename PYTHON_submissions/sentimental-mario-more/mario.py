def get_PositiveInt(prompt):
    while True:
        try:
            intValue = int(input(prompt))
            if intValue > 0 and intValue <= 8:
                return intValue
            else:
                print("Enter a positive integer between 1 and 8!")
        except ValueError:
            print("error!")


def main():

    height = get_PositiveInt("Height: ")

    spaceLeft = height - 1

    for i in range(1, height + 1):
        print(' ' * spaceLeft + '#' * i + '  ' + '#' * i)
        spaceLeft -= 1


main()
