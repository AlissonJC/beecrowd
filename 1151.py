n = int(input())

fibo = [0, 1]

for i in range(2, n):
    value = fibo[i-1] + fibo[i-2]
    fibo.append(value)

result = ' '.join(str(item) for item in fibo)
print(result)