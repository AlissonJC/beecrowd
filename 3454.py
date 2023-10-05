game = input().upper()

if game == "XXO" or game == "OXX":
    print("Alice")
elif game == "XOX":
    print("*")
elif game == "OOX" or game == "XOO" or game == "OXO" or game == "XXX" or game == "OOO":
    print("?")