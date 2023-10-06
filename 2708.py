salida = 0
vuelta = 0
total_passengers = 0
jeep = salida - vuelta
try:
    word = input()
    action, passengers = word.split()
except ValueError:
    print(f"{total_passengers}")
    print(f"{jeep}")
    quit()
passengers = int(passengers)

while True:
    if action == "ABEND":
        break
    elif action == "SALIDA":
        salida += 1
        total_passengers += passengers
    elif action == "VUELTA":
        vuelta += 1
        total_passengers -= passengers
    try:
        word = input()
        action, passengers = word.split()
    except ValueError:
        break
    passengers = int(passengers)

print(f"{total_passengers}")
print(f"{jeep}")