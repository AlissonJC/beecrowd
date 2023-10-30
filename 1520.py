def binary_search(v, p):
    l, r = 0, len(v) - 1
    while l <= r:
        mid = (l + r) // 2
        if v[mid] == p:
            return mid
        if p < v[mid]:
            r = mid - 1
        else:
            l = mid + 1
    return -1

while True:
    try:
        n = int(input())
        if n == -1:
            break

        j = 0
        v = []
        for _ in range(n):
            x, y = map(int, input().split())
            v.extend(range(x, y + 1))

        v.sort()
        a = int(input())
        ans = binary_search(v, a)

        if ans == -1:
            print(f"{a} not found")
        else:
            there = ans
            here = ans
            for i in range(ans + 1, len(v)):
                if v[i] == a:
                    there = i
                else:
                    break
            for i in range(ans, -1, -1):
                if v[i] == a:
                    here = i
                else:
                    break

            print(f"{a} found from {here} to {there}")

    except EOFError:
        break
    except:
        continue