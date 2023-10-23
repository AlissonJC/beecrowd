n = int(input())

for i in range(n):
    led = input()

    count_led = 0

    for i in range(len(led)):
        if led[i] == "0":
            count_led += 6
        elif led[i] == "1":
            count_led += 2
        elif led[i] == "2":
            count_led += 5
        elif led[i] == "3":
            count_led += 5
        elif led[i] == "4":
            count_led += 4
        elif led[i] == "5":
            count_led += 5
        elif led[i] == "6":
            count_led += 6
        elif led[i] == "7":
            count_led += 3
        elif led[i] == "8":
            count_led += 7
        elif led[i] == "9":
            count_led += 6

    print(f"{count_led} leds")