t = int(input())

for i in range(1, t+1):
    approach = input()
    r, g, b = map(int, input().split())

    if approach == "eye":
        p = int(r * 0.3 + g * 0.59 + b * 0.11)
        print(f"Caso #{i}: {p}")
    elif approach == "mean":
        p = int((r + g + b) / 3)
        print(f"Caso #{i}: {p}")
    elif approach == "min":
        if r <= g and r <= b:
            p = r
        elif g <= r and g <= b:
            p = g
        elif b <= g and b <= r:
            p = b
        print(f"Caso #{i}: {p}")
    elif approach == "max":
        if r >= g and r >= b:
            p = r
        elif g >= r and g >= b:
            p = g
        elif b >= g and b >= r:
            p = b
        print(f"Caso #{i}: {p}")