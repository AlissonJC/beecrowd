def fibonacci(n):
    fib = list()
    fib.append(0)
    fib.append(1)

    if n == 0:
        return 0
    elif n == 1:
        return 1


    for i in range(2, n+1):
        fib.append(fib[i-1] + fib[i-2])

    return fib[n]

t = int(input())

for i in range(t):
    n = int(input())
    res = fibonacci(n)
    print(f"Fib({n}) = {res}")