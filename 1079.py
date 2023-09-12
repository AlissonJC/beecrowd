n = int(input())

averages = []

while n > 0:
    for test in range(n):
        grade_1, grade_2, grade_3 = map(float, input().split())
        average = (grade_1 * 2 + grade_2 * 3 + grade_3 * 5)/10
        averages.append(average)
        n -= 1

for average in range(len(averages)):
    print(f"{averages[average]:.1f}")