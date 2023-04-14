a, b, c = map(float, input().split())

if a > b  and a > c:
    pass
elif b > a and b > c:
    aux = b
    b = a
    a = aux
elif c > a and c > b:
    aux = c
    c = a
    a = aux


if a >= (b + c):
    print("NAO FORMA TRIANGULO")
elif a**2 == (b**2 + c**2):
    print("TRIANGULO RETANGULO")
elif a**2 > (b**2 + c**2):
    print("TRIANGULO OBTUSANGULO")
elif a**2 < (b**2 + c**2):
    print("TRIANGULO ACUTANGULO")

if a == b == c:
    print("TRIANGULO EQUILATERO")
elif (a == b and a != c) or (a == c and a != b) or (b == c and b != a):
    print("TRIANGULO ISOSCELES")