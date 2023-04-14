# In this problem you have to read an integer value and calculate the smallest
# possible number of banknotes in which the value may be decomposed. The possible
# banknotes are 100, 50, 20, 10, 5, 2 e 1. Print the read value and the list of banknotes.
#
# Input
# The input file contains an integer value N (0 < N < 1000000).
#
# Output
# Print the read number and the minimum quantity of each necessary banknotes in
# Portuguese language, as the given example. Do not forget to print the end of line
# after each line, otherwise you will receive “Presentation Error”.

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