a, b, c = map(float, input().split())

p = (a+b+c)/2

a = (p * (p - a) * (p - b) * (p - c)) ** (1/2)

print(f"{a:.3f} m2")