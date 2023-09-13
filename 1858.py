n = int(input())

hits = [int(num) for num in input().split(" ", n-1)]

choice = hits.index(min(hits)) + 1

print(choice)