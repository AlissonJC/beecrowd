def print_matrix_123(size):
    matrix = [[0] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            if row == col:
                matrix[row][col] = 1
            if row == size - col - 1:
                matrix[row][col] = 2
            if row != col and row != size - col - 1:
                matrix[row][col] = 3

    for row in range(size):
        for col in range(size):
            print(matrix[row][col], end='')
        print()

while True:
    try:
        size = int(input())
        print_matrix_123(size)
    except EOFError:
        break