n = int(input())

if n % 2 == 0:
    white = (n * n) / 2
    black = (n * n) / 2
else:
    white = ((n * n) / 2) + 1
    black = (n * n) / 2

print(f"{int(white)} casas brancas e {int(black)} casas pretas")