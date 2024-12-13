def get_float():
    while True:
        try:
            n = float(input("Amount: "))
            if n < 0:
                n = float(input("Amount: "))
            return n
        except ValueError:
            pass


def quarter(cent):
    return cent // 25


def ten(cent):
    return cent // 10


def five(cent):
    return cent // 5


def one(cent):
    return cent


def main():
    n = get_float()*100
    quarters = quarter(n)
    n -= quarters*25
    tens = ten(n)
    n -= tens*10
    fives = five(n)
    n -= fives*5
    ones = one(n)
    total = quarters + tens + fives + ones
    print(int(total))


main()
