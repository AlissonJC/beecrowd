n = int(input())

arr = list(map(int, input().split()))

min = min(arr)
pos = arr.index(min)

print(f"Menor valor: {min}")
print(f"Posicao: {pos}")