while True:
    try:
        number, id = map(int, input().split())
        count = 0
        while number > 0:
            i, j = map(int, input().split())
            if id == i and j == 0:
                count += 1
            number -= 1
        print(count)
    except EOFError:
        break