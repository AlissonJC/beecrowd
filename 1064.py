a = float(input())
b = float(input())
c = float(input())
d = float(input())
e = float(input())
f = float(input())

positive_numbers = 0
sum_of_positives = 0

if a > 0:
    positive_numbers += 1
    sum_of_positives += a
if b > 0:
    positive_numbers += 1
    sum_of_positives += b
if c > 0:
    positive_numbers += 1
    sum_of_positives += c
if d > 0:
    positive_numbers += 1
    sum_of_positives += d
if e > 0:
    positive_numbers += 1
    sum_of_positives += e
if f > 0:
    positive_numbers += 1
    sum_of_positives += f

print(f"{positive_numbers} valores positivos")
print(f"{sum_of_positives/positive_numbers:.1f}")