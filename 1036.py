a, b, c = map(float, input().split())

if a == 0 or (b*b -4*a*c) < 0:
    print("Impossivel calcular")
else:
    r1 = (-b + (b * b - 4 * a * c) ** (1 / 2))/(2 * a)
    r2 = (-b - (b * b - 4 * a * c) ** (1 / 2))/(2 * a)
    print(f"R1 = {r1:.5f}")
    print(f"R2 = {r2:.5f}")