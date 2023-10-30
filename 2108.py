max_word = ""
while True:
    str = input()
    if str == "0":
        print("\nThe biggest word:", max_word)
        break
    else:
        temp = ""
        for char in str:
            if char != ' ':
                temp += char
            else:
                if len(temp) >= len(max_word):
                    max_word = temp
                print(len(temp), end="-")
                temp = ""
        if temp:
            print(len(temp))
            if len(temp) >= len(max_word):
                max_word = temp