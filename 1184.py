def main():
    c = 12
    m = [[0.0] * c for _ in range(c)]
    soma = 0.0
    media = 0.0
    elementos = 0

    o = input()

    for i in range(c):
        for j in range(c):
            m[i][j] = float(input())

    for i in range(c):
        for j in range(i):
            soma += m[i][j]
            elementos += 1

    if o == 'S':
        print(f'{soma:.1f}')
    else:
        media = soma / elementos
        print(f'{media:.1f}')

if __name__ == "__main__":
    main()