first_product_code, first_product_units, first_product_price = input().split()
second_product_code, second_product_units, second_product_price = input().split()

first_product_total = int(first_product_units) * float(first_product_price)
second_product_total = int(second_product_units) * float(second_product_price)

total = first_product_total + second_product_total

print(f"VALOR A PAGAR: R$ {total:.2f}")