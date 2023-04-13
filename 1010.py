# In this problem, the task is to read a code of a product 1, the number of
# units of product 1, the price for one unit of product 1, the code of a product 2,
# the number of units of product 2 and the price for one unit of product 2. After this,
# calculate and show the amount to be paid.
#
# Input
# The input file contains two lines of data. In each line there will be 3 values:
# two integers and a floating value with 2 digits after the decimal point.
#
# Output
# The output file must be a message like the following example where "Valor a pagar"
# means Value to Pay. Remember the space after ":" and after "R$" symbol. The value must
# be presented with 2 digits after the point.

first_product_code, first_product_units, first_product_price = input().split()
second_product_code, second_product_units, second_product_price = input().split()

first_product_total = int(first_product_units) * float(first_product_price)
second_product_total = int(second_product_units) * float(second_product_price)

total = first_product_total + second_product_total

print(f"VALOR A PAGAR: R$ {total:.2f}")