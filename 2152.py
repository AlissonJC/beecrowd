n = int(input())

for i in range(n):
    h, m, o = map(int, input().split())

    if o == 0:
        door = "fechou"
    elif o == 1:
        door = "abriu"

    print(f"{h:02d}:{m:02d} - A porta {door}!")