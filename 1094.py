count = int(input())

rabits = 0
frogs = 0
rats = 0

while count > 0:
    amount, type = input().split()
    amount = int(amount)
    if type == "C":
        rabits += amount
    elif type == "R":
        rats += amount
    elif type == "S":
        frogs += amount
    count -= 1

print(f"Total: {rabits+frogs+rats} cobaias")
print(f"Total de coelhos: {rabits}")
print(f"Total de ratos: {rats}")
print(f"Total de sapos: {frogs}")
print(f"Percentual de coelhos: {rabits/(rabits+frogs+rats)*100:.2f} %")
print(f"Percentual de ratos: {rats/(rabits+frogs+rats)*100:.2f} %")
print(f"Percentual de sapos: {frogs/(rabits+frogs+rats)*100:.2f} %")