f1, f2 = map(float, input().split())

f1 = f1/100 + 1
f2 = f2/100 + 1

gdp = ((f1 * f2) - 1) * 100

print(f"{gdp:.6f}")