def main():

    card = get_PositiveInt("Number: ")
    card_len = check_len(card)

    if card_len == 13 or card_len == 15 or card_len == 16:
        card_luhnAlgorithm = luhnAlgorithm(card)

        if card_luhnAlgorithm == 0:
            print(check_brand(card, card_len))
        else:
            print("INVALID")
    else:
        print("INVALID")


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


def check_len(digits):
    digits_str = str(digits)
    digits_len = len(digits_str)

    return digits_len


def luhnAlgorithm(card_number):
    card = card_number
    sum_1 = 0
    sum_2 = 0

    while card > 0:
        digit = card % 10
        sum_1 += digit
        card //= 10

        digit = card % 10
        doubled_digit = digit * 2
        sum_2 += doubled_digit // 10 + doubled_digit % 10
        card //= 10

    total_sum = sum_1 + sum_2
    last_digit = total_sum % 10

    return last_digit


def check_brand(card, card_len):
    card_str = str(card)

    first_digit = card_str[0]
    second_digit = card_str[1]
    first_two_digits = first_digit + second_digit

    if (card_len == 16 and (first_two_digits >= "51" and first_two_digits <= "55")):
        return "MASTERCARD"
    elif (card_len == 15 and (first_two_digits == "34" or first_two_digits == "37")):
        return "AMEX"
    elif ((card_len == 13 or card_len == 16) and first_digit == "4"):
        return "VISA"
    else:
        return "INVALID"


main()
