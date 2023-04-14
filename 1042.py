n1, n2, n3 = map(int, input().split())

input_order = [n1, n2, n3]

if n1 < n2 and n1 < n3:
    print(n1)
    if n2 < n3:
        print(n2)
        print(n3)
    elif n2 > n3:
        print(n3)
        print(n2)
if n2 < n1 and n2 < n3:
    print(n2)
    if n1 < n3:
        print(n1)
        print(n3)
    elif n1 > n3:
        print(n3)
        print(n1)
if n3 < n1 and n3 < n2:
    print(n3)
    if n1 < n2:
        print(n1)
        print(n2)
    elif n2 < n1:
        print(n2)
        print(n1)

print()
for number in input_order:
    print(number)