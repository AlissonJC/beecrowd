def calculate_score(throws):
    score = 0
    for x, d in throws:
        score += x * d
    return score

def determine_winner(john, mary):
    john_score = calculate_score(john)
    mary_score = calculate_score(mary)

    if john_score > mary_score:
        return "JOAO"
    elif mary_score > john_score:
        return "MARIA"
    else:
        return "EMPATE"

N = int(input())

for _ in range(N):
    john = [list(map(int, input().split())) for _ in range(3)]
    mary = [list(map(int, input().split())) for _ in range(3)]

    winner = determine_winner(john, mary)
    print(winner)