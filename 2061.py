tabs, actions = map(int, input().split())

for i in range(actions):
    action = input()

    if action == "fechou":
        tabs += 1
    elif action == "clicou":
        tabs -= 1

print(tabs)