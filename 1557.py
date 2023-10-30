while True:
    size = int(input())

    if size == 0:
        break

    matrix = [[0] * size for _ in range(size)]
    element = 1

    for line in range(size):
        for column in range(size):
            matrix[line][column] = element
            element *= 2

        element = matrix[line][0] * 2

    digits = 0
    t = matrix[size - 1][size - 1]

    while t > 0:
        t % 10
        t = t // 10
        digits += 1

    for line in range(size):
        for column in range(size):
            if column == 0:
                print(f'{matrix[line][column]:{digits}}', end='')
            else:
                print(f' {matrix[line][column]:{digits}}', end='')
        print()
    print()