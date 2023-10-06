s = 0

n = 1
d = 1

for i in range(20):
    s += n/d
    n += 2
    d *= 2

print(f"{s:.2f}")