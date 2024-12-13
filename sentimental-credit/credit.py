from cs50 import get_int

def check_sum(credit):
    total = 0
    var = True
    x = 0
    while (credit > 0):
        if var == True:
            total += credit % 10
            credit //= 10
            var = False
        else:
            x = credit % 10
            x *= 2
            if (x >= 10):
                total += x % 10
                total += x // 10
            else:
                total += x
            var = True
            credit //= 10
    if total % 10 == 0:
        return True
    print("INVALID")
    return False

def main():
    digits = 0
    single_digit = 0
    two_digit = 0
    checksum = True
    credit = get_int("Credit/ ")
    checksum = check_sum(credit)
    if checksum == False:
        return 0
    while credit > 0:
        if credit < 10:
            single_digit = credit
        if credit > 10 and credit < 100:
            two_digit = credit
        credit //= 10
        digits += 1
    print("digits: ", digits)
    print("single_digit: ", single_digit)
    print("two_digit: ", two_digit)
    if ((two_digit == 34 or two_digit == 37) and digits == 15):
        print("AMEX")
        return 0
    elif ((two_digit == 51 or two_digit == 52 or two_digit == 53 or two_digit == 54 or two_digit == 55) and digits == 16):
        print("MASTERCARD\n")
        return 0
    elif (single_digit == 4 and (digits == 13 or digits == 16)):
        print("VISA\n")
        return 0
    else:
        print("INVALID\n")
    return 0

main()
