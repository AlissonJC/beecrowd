sellers_name = input()
salary = float(input())
sales_made = float(input())

commission = sales_made * 0.15

total = salary + commission

print(f"TOTAL = R$ {total:.2f}")