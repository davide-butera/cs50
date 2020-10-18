from cs50 import get_string


def is_valid(string):
    reverse = map(int, reversed(string))
    sum = 0
    for idx, digit in enumerate(reverse):
        if idx % 2 != 0:
            digit *= 2
            if digit > 9:
                sum += digit // 10 % 10 + digit % 10
            else:
                sum += digit
        elif idx % 2 == 0:
            sum += digit
    return sum % 10 == 0



def is_amex(n):
    return (n[0] == '3' and (n[1] == '4' or n[1] == '7') and len(n) == 15)


def is_mastercard(n):
    return (n[0] == '5' and (int(n[1]) in range(1, 6)) and len(n) == 16)


def is_visa(n):
    return (n[0] == '4' and (len(n) == 13 or len(n) == 16))


number = get_string("Number: ")

if is_valid(number):
    if is_amex(number):
        print("AMEX")
    elif is_mastercard(number):
        print("MASTERCARD")
    elif is_visa(number):
        print("VISA")
    else:
        print("Valid but not recognised")
else:
    print("INVALID")
