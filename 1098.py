i, j = 0, 1

while j >= 1:
    print(f"I={i} J={j}")
    j += 1
    print(f"I={i} J={j}")
    j += 1
    print(f"I={i} J={j}")
    i += 0.2
    j = 1
    j += i
    i = round(i, 1)
    j = round(j, 1)
    if i.is_integer():
        i = int(i)
    if j.is_integer():
        j = int(j)
    if i > 2:
        break