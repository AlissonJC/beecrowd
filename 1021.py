value = float(input())
value += 0.001

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

one_coin = value // 1
value -= one_coin * 1
half_coin = value // 0.50
value -= half_coin * 0.50
quarter_coin = value // 0.25
value -= quarter_coin * 0.25
ten_coin = value // 0.10
value -= ten_coin * 0.10
five_coin = value // 0.05
value -= five_coin * 0.05
cent = value // 0.01

print("NOTAS:")
print(f"{hundreds:.0f} nota(s) de R$ 100.00")
print(f"{fifties:.0f} nota(s) de R$ 50.00")
print(f"{twenties:.0f} nota(s) de R$ 20.00")
print(f"{tens:.0f} nota(s) de R$ 10.00")
print(f"{fives:.0f} nota(s) de R$ 5.00")
print(f"{twos:.0f} nota(s) de R$ 2.00")
print("MOEDAS:")
print(f"{one_coin:.0f} moeda(s) de R$ 1.00")
print(f"{half_coin:.0f} moeda(s) de R$ 0.50")
print(f"{quarter_coin:.0f} moeda(s) de R$ 0.25")
print(f"{ten_coin:.0f} moeda(s) de R$ 0.10")
print(f"{five_coin:.0f} moeda(s) de R$ 0.05")
print(f"{cent:.0f} moeda(s) de R$ 0.01")