import math

x, y = map(int, input().split())

x = abs(y - x)
lap = math.ceil(y/x)

print(lap)