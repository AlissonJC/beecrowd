n, m = map(int, input().split())

fruits = []
viruses = []

for i in range(n):
    fruit = input().lower()
    fruits.append(fruit)

for i in range(m):
    virus = input().lower()
    viruses.append(virus)

found = []

for j in range(len(fruits)):
    for i in range(len(viruses)):
        if fruits[j] in viruses[i] or fruits[j][::-1] in viruses[i]:
            found.append(fruits[j])

for i in range(len(fruits)):
    if fruits[i] in found:
        print(f"Sheldon come a fruta {fruits[i]}")
    else:
        print(f"Sheldon detesta a fruta {fruits[i]}")