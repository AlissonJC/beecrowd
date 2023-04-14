first_word = input()
second_word = input()
third_word = input()

if first_word == "vertebrado":
    if second_word == "ave":
        if third_word == "carnivoro":
            print("aguia")
        elif third_word == "onivoro":
            print("pomba")
    elif second_word == "mamifero":
        if third_word == "onivoro":
            print("homem")
        elif third_word == "herbivoro":
            print("vaca")

elif first_word == "invertebrado":
    if second_word == "inseto":
        if third_word == "hematofago":
            print("pulga")
        elif third_word == "herbivoro":
            print("lagarta")
    elif second_word == "anelideo":
        if third_word == "hematofago":
            print("sanguessuga")
        elif third_word == "onivoro":
            print("minhoca")