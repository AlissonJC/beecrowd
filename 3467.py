while True:
    try:
        word = input().lower()
        if word[2] == "l":
            print("Esse eh o meu lugar")
        elif word[2] == "x":
            print("Oi, Leonard")
    except EOFError:
        break