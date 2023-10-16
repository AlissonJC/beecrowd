n = int(input())

for i in range(n):
    x = input()

    if x == "P=NP":
        print("skipped")
    else:
        a, b = x.split("+")

        print(int(a)+int(b))