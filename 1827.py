def create_matrix(size):
    m = [[0] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            if row == col:
                m[row][col] = 2
            elif row == size - col - 1:
                m[row][col] = 3
            else:
                m[row][col] = 0

    start = size // 3
    end = size - start

    for row in range(start, end):
        for col in range(start, end):
            m[row][col] = 1

    m[size // 2][size // 2] = 4

    for row in range(size):
        for col in range(size):
            print(m[row][col], end='')
        print()
    print()

while True:
    try:
        size = int(input())
        create_matrix(size)
    except EOFError:
        break