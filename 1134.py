alcohol = 0
diesel = 0
gas = 0

a = int(input())

while True:
    if a == 4:
        print("MUITO OBRIGADO")
        break
    elif a == 1:
        alcohol += 1
    elif a == 2:
        gas += 1
    elif a == 3:
        diesel += 1
    else:
        pass
    a = int(input())
print(f"Alcool: {alcohol}")
print(f"Gasolina: {gas}")
print(f"Diesel: {diesel}")