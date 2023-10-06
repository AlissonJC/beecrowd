from statistics import median

n = int(input())

p = input().split()
views = [eval(i) for i in p]

print(int(median(views)))