N = int(input())
K = int(input())
scores = []

for _ in range(N):
    score = int(input())
    scores.append(score)

scores.sort(reverse=True)
cutoff_score = scores[K - 1]
qualified = 0

for score in scores:
    if score >= cutoff_score:
        qualified += 1

print(qualified)
