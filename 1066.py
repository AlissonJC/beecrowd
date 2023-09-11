a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

odd_count = 0
even_count = 0
positive_count = 0
negative_count = 0

if a % 2 == 0:
    even_count += 1
else:
    odd_count += 1

if b % 2 == 0:
    even_count += 1
else:
    odd_count += 1

if c % 2 == 0:
    even_count += 1
else:
    odd_count += 1

if d % 2 == 0:
    even_count += 1
else:
    odd_count += 1

if e % 2 == 0:
    even_count += 1
else:
    odd_count += 1

if a > 0:
    positive_count += 1
elif a < 0:
    negative_count += 1

if b > 0:
    positive_count += 1
elif b < 0:
    negative_count += 1

if c > 0:
    positive_count += 1
elif c < 0:
    negative_count += 1

if d > 0:
    positive_count += 1
elif d < 0:
    negative_count += 1

if e > 0:
    positive_count += 1
elif e < 0:
    negative_count += 1

print(f"{even_count} valor(es) par(es)")
print(f"{odd_count} valor(es) impar(es)")
print(f"{positive_count} valor(es) positivo(s)")
print(f"{negative_count} valor(es) negativo(s)")