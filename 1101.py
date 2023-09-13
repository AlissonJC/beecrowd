pairs = []

while True:
    m, n = map(int, input().split())
    if m <= 0 or n <= 0:
        break

    if m > n:
        m, n = n, m

    sequence = list(range(m, n+1))
    total_sum = sum(range(m, n+1))

    pairs.append((sequence, total_sum))

for sequence, total_sum in pairs:
    print(' '.join(map(str, sequence)), f"Sum={total_sum}")