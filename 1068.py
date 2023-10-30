while True:
    try:
        expr = input().strip()

        correct = True
        parenthesis = 0

        for chr in expr:
            if chr == '(':
                parenthesis += 1
            elif chr == ')':
                if parenthesis > 0:
                    parenthesis -= 1
                else:
                    correct = False
                    break

        correct = correct and (parenthesis == 0)

        print("correct" if correct else "incorrect")
    except EOFError:
        break