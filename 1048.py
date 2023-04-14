salary = float(input())

if 0 < salary <= 400:
    adjustment_rate = 0.15
    increase = salary * adjustment_rate
    new_salary = increase + salary
    print(f"Novo salario: {new_salary:.2f}")
    print(f"Reajuste ganho: {increase:.2f}")
    print(f"Em percentual: {adjustment_rate * 100:.0f} %")
elif 400 < salary <= 800:
    adjustment_rate = 0.12
    increase = salary * adjustment_rate
    new_salary = increase + salary
    print(f"Novo salario: {new_salary:.2f}")
    print(f"Reajuste ganho: {increase:.2f}")
    print(f"Em percentual: {adjustment_rate * 100:.0f} %")
elif 800 < salary <= 1200:
    adjustment_rate = 0.10
    increase = salary * adjustment_rate
    new_salary = increase + salary
    print(f"Novo salario: {new_salary:.2f}")
    print(f"Reajuste ganho: {increase:.2f}")
    print(f"Em percentual: {adjustment_rate * 100:.0f} %")
elif 1200 < salary <= 2000:
    adjustment_rate = 0.07
    increase = salary * adjustment_rate
    new_salary = increase + salary
    print(f"Novo salario: {new_salary:.2f}")
    print(f"Reajuste ganho: {increase:.2f}")
    print(f"Em percentual: {adjustment_rate * 100:.0f} %")
elif salary > 2000:
    adjustment_rate = 0.04
    increase = salary * adjustment_rate
    new_salary = increase + salary
    print(f"Novo salario: {new_salary:.2f}")
    print(f"Reajuste ganho: {increase:.2f}")
    print(f"Em percentual: {adjustment_rate * 100:.0f} %")