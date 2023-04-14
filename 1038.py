code, amount = map(int, input().split())

if code == 1:
    price = 4.00
    total = price * amount
    print(f"Total: R$ {total:.2f}")
elif code == 2:
    price = 4.50
    total = price * amount
    print(f"Total: R$ {total:.2f}")
elif code == 3:
    price = 5.00
    total = price * amount
    print(f"Total: R$ {total:.2f}")
elif code == 4:
    price = 2.00
    total = price * amount
    print(f"Total: R$ {total:.2f}")
elif code == 5:
    price = 1.50
    total = price * amount
    print(f"Total: R$ {total:.2f}")