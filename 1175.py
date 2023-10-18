n = list()

for i in range(20):
    x = int(input())
    n.append(x)

l = n.reverse()

for i in range(len(n)):
    print(f"N[{i}] = {n[i]}")