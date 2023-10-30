def calculate_square_root(N):
    a = [3]
    for i in range(N):
        a.append(6)
    a = a[::-1]

    x = a[0]
    for i in range(1, N + 1):
        x = a[i] + 1 / x

    return x

N = int(input())

result = calculate_square_root(N)

print(f'{result:.10f}')