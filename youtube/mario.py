def get_int(x):
    while True:
        try:
            return int(input(x))
        except  ValueError:
            pass


while True:
    n = get_int("height:")
    if n > 0:
        break

for i in range(n):
    for j in range(n):
        print("#", end = "")
    print()
