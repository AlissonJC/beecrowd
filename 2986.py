MOD = 1000000007

def count_ways_to_climb_stairs(n):
    if n <= 2:
        return n
    if n == 3:
        return 4

    ways = [0] * (n + 1)
    ways[1] = 1
    ways[2] = 2
    ways[3] = 4

    for i in range(4, n + 1):
        ways[i] = (((ways[i - 1] + ways[i - 2]) % MOD + ways[i - 3]) % MOD) % MOD

    return ways[n]

n = int(input())

result = count_ways_to_climb_stairs(n)

print(f"{result:.0f}")