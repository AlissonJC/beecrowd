c = int(input())

for i in range(c):
    power = input()

    power = power[1:-2]
    part1, part2 = power.split("mek")

    res = part1.count("a") * part2.count("a")

    print("k"+"a"*res)