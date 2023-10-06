n = int(input())

won = 0

for i in range(n):
    word = input().upper()

    if "CD" not in word:
        won += 1

print(won)