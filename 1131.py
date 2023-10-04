gremio_wins = 0
inter_wins = 0
draws = 0

inter, gremio = map(int, input().split())
if gremio > inter:
    gremio_wins += 1
elif gremio < inter:
    inter_wins += 1
else:
    draws += 1

op = int(input("Novo grenal (1-sim 2-nao)\n"))
while True:
    if op == 2:
        break

    inter, gremio = map(int, input().split())

    if gremio > inter:
        gremio_wins += 1
    elif gremio < inter:
        inter_wins += 1
    else:
        draws += 1
    op = int(input("Novo grenal (1-sim 2-nao)\n"))

print(f"{gremio_wins+inter_wins+draws} grenais")
print(f"Inter:{inter_wins}")
print(f"Gremio:{gremio_wins}")
print(f"Empates:{draws}")

if gremio_wins > inter_wins:
    print("Gremio venceu mais")
elif gremio_wins < inter_wins:
    print("Inter venceu mais")
else:
    print("Não houve vencedor")