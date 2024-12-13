def main():
    x = int(input("X: "))
    if even(x):
        print("Even")
    else:
        print("odd")

def even(n):
    return n%2 == 0

main()

