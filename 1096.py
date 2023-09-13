i, j = 1, 7

while j >= 5:
    print(f"I={i} J={j}")
    j -= 1
    print(f"I={i} J={j}")
    j -= 1
    print(f"I={i} J={j}")
    j = 7
    i += 2
    if i > 9:
        break