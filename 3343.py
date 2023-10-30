def read_int(prompt):
    return list(map(int, input(prompt).split()))

entry = read_int("")
titans = input()
size = read_int("")

n, x = entry[0], entry[1]
t1, t2, t3 = size[0], size[1], size[2]
walls = [x] * n
p, m, g = 0, 0, 0

for t in titans:
    if t == 'P':
        while p < n and walls[p] < t1:
            p += 1
        if p < n:
            walls[p] -= t1
    elif t == 'M':
        while m < n and walls[m] < t2:
            m += 1
        if m < n:
            walls[m] -= t2
    else:
        while g < n and walls[g] < t3:
            g += 1
        if g < n:
            walls[g] -= t3

result = [p + 1, m + 1, g + 1]
print(max(result))