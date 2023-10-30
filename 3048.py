N = int(input())
sequence = []
for i in range(N):
    v = int(input())
    sequence.append(v)


actual = sequence[0]
i = 1
consecutive = 0

while i < N:
    if actual == 1:
        j = i
        while j < N:
            if sequence[j] == 2:
                break
            j += 1
        i = j
        actual = 2
    else:
        j = i
        while j < N:
            if sequence[j] == 1:
                break
            j += 1
        i = j
        actual = 1
    consecutive += 1

print(consecutive)