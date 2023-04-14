salary = float(input())

if salary > 4500:
    tax_1 = (salary - 4500)
    tax_2 = (salary - tax_1 - 3000)
    tax_3 = (salary - tax_1 - tax_2 - 2000)
    tax_total = tax_1*0.28 + tax_2*0.18 + tax_3*0.08
    print(f"R$ {tax_total:.2f}")
elif 3000 < salary <= 4500:
    tax_1 = (salary - 3000)
    tax_2 = (salary - tax_1 - 2000)
    tax_total = tax_1*0.18 + tax_2*0.08
    print(f"R$ {tax_total:.2f}")
elif 2000 < salary <= 3000:
    tax_1 = (salary - 2000)
    tax_total = tax_1*0.08
    print(f"R$ {tax_total:.2f}")
elif 0 < salary <= 2000:
    print("Isento")