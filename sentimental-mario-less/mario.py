def get_int():
    while True:
        try:
            n = int(input("height: "))
            while n <= 0 or n > 8:
                n = int(input("height: "))
            return n
        except ValueError:
            pass

def main():
    n = get_int()
    for i in range(1, n + 1):
        for k in range(n - i):
            print(" ", end="")
        for j in range(i):
            print("#", end="")
        print()

main()
