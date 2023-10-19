_row = int(input())
op = input()

const = 12

matrix = []

for row in range(const):
    a = []
    for column in range(const):
        a.append(float(input()))
    matrix.append(a)

total = []
for row in range(const):
    for column in range(const):
        total.append(matrix[_row][column])
    break

if op == "S":
    print(f"{sum(total):.1f}")
elif op == "M":
    print(f"{sum(total)/const:.1f}")