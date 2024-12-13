def get_int():
    while True:
        try:
            n = int(input("Heights: "))
            while n <= 0 or n > 8:
                n = int(input("Heights: "))
            return n
        except ValueError:
            pass


def main():
    n = get_int()  # Assuming this function gets a valid integer input
    for i in range(n):
        # Print leading spaces for the left pyramid
        for j in range(n - i - 1):
            print(" ", end="")  # Stay on the same line for spaces

        # Print left pyramid of hashes
        for k in range(i + 1):  # +1 to ensure at least one # is printed
            print("#", end="")

        # Print gap between the two pyramids
        print("  ", end="")  # Print the gap without moving to a new line

        # Print right pyramid of hashes
        for m in range(i + 1):  # +1 to ensure at least one # is printed
            print("#", end="")

        # Move to the next line after completing the row
        print()


main()
