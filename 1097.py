i, j = 1, 7

jota = 7

while j >= 5:
    print(f"I={i} J={j}")
    j -= 1
    print(f"I={i} J={j}")
    j -= 1
    print(f"I={i} J={j}")
    jota += 2
    j = jota
    i += 2
    if i > 9:
        break