def can_win_game(P, N, heights):
    for i in range(N - 1):
        if abs(heights[i] - heights[i + 1]) > P:
            return "GAME OVER"
    return "YOU WIN"

P, N = map(int, input().split())
heights = list(map(int, input().split()))

result = can_win_game(P, N, heights)
print(result)