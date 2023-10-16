while True:
    try:
        t = int(input())

        tests = []

        for i in range(t):
            x = float(input())
            tests.append(x)

        print(f"{min(tests):.2f}")
    except:
        break