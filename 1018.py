value = int(input())

print(f"{value}")

hundreds = value // 100
value -= hundreds * 100
fifties = value // 50
value -= fifties * 50
twenties = value // 20
value -= twenties * 20
tens = value // 10
value -= tens * 10
fives = value // 5
value -= fives * 5
twos = value // 2
value -= twos * 2
ones = value // 1

print(f"{hundreds:.0f} nota(s) de R$ 100,00")
print(f"{fifties:.0f} nota(s) de R$ 50,00")
print(f"{twenties:.0f} nota(s) de R$ 20,00")
print(f"{tens:.0f} nota(s) de R$ 10,00")
print(f"{fives:.0f} nota(s) de R$ 5,00")
print(f"{twos:.0f} nota(s) de R$ 2,00")
print(f"{ones:.0f} nota(s) de R$ 1,00")