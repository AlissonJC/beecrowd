operation = input()

M = []
for i in range(12):
    row = []
    for j in range(12):
        row.append(float(input()))
    M.append(row)

sum_value = 0.0
elements = 0

for i in range(12):
    for j in range(i + 1, 12):
        sum_value += M[i][j]
        elements += 1

if operation == 'M':
    sum_value /= elements

print(f'{sum_value:.1f}')
