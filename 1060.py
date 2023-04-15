n1 = float(input())
n2 = float(input())
n3 = float(input())
n4 = float(input())
n5 = float(input())
n6 = float(input())

positives = 0

if n1 > 0:
    positives += 1
if n2 > 0:
    positives += 1
if n3 > 0:
    positives += 1
if n4 > 0:
    positives += 1
if n5 > 0:
    positives += 1
if n6 > 0:
    positives += 1

print(f"{positives} valores positivos")