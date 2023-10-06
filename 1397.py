while True:
    n = int(input())
    if n == 0:
        break

    player_a = 0
    player_b = 0

    for match in range(n):
        a, b = map(int, input().split())
        if a > b:
            player_a += 1
        elif b > a:
            player_b += 1
    print(f"{player_a} {player_b}")