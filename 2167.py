n = int(input())
def check_failure(tests):

    for i in range(len(tests)-1):
        if tests[i] > tests[i+1]:
            return i+2
    return 0

tests = list(map(int, input().split()))

x = check_failure(tests)

print(x)