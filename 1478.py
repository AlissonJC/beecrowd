while True:
    N = int(input())
    if N == 0:
        break

    matriz = [[0] * N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            matriz[i][j] = abs(i - j) + 1

    for i in range(N):
        for j in range(N):
            if j == N - 1:
                print(f'{matriz[i][j]:3}')
            else:
                print(f'{matriz[i][j]:3}', end=' ')
    print()