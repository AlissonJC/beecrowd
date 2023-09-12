counter = int(input())

inside = []
outside = []

while counter > 0:
    x = int(input())

    if 10 <= x <= 20:
        inside.append(x)
    else:
        outside.append(x)

    counter -= 1

print(f"{len(inside)} in")
print(f"{len(outside)} out")