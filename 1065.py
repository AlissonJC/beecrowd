a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

even_count = 0

if a % 2 == 0:
    even_count += 1
if b % 2 == 0:
    even_count += 1
if c % 2 == 0:
    even_count += 1
if d % 2 == 0:
    even_count += 1
if e % 2 == 0:
    even_count += 1

print(f"{even_count} valores pares")