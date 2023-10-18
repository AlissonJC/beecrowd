n = int(input())

for i in range(n):
    player1, choice1, player2, choice2 = input().split()
    n1, n2 = map(int, input().split())

    if choice1 == "PAR" and (n1+n2) % 2 == 0:
        print(player1)
    elif choice1 == "IMPAR" and (n1+n2) % 2 != 0:
        print(player1)
    elif choice2 == "PAR" and (n1+n2) % 2 == 0:
        print(player2)
    elif choice2 == "IMPAR" and (n1+n2) % 2 != 0:
        print(player2)