row = int(input())

op = input()

M = []
for i in range(12):
    line = []
    for j in range(12):
        line.append(float(input()))
    M.append(line)

total = 0.0

for i in range(12):
    total += M[row][i]

if op == 'M':
    total /= 12

print(f'{total:.1f}')