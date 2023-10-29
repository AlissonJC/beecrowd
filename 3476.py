S, B, C = map(int, input().split())

inv_S = 1 / S
inv_B = 1 / B
inv_C = 1 / C

avg_time = 1 / (inv_S + inv_B + inv_C)

print(f"{avg_time:.3f}")