n = int(input())

vowels = ['a', 'e', 'i', 'o', 'u']

def check_consonant_sequence(word):

        for i in range(len(word)):
            if word[i] not in vowels:
                if i+1 < len(word):
                    if word[i+1] not in vowels:
                        if i+2 < len(word):
                            if word[i+2] not in vowels:
                                return f"{word.capitalize()} nao eh facil"

        return f"{word.capitalize()} eh facil"

for i in range(n):
    word = input().lower()
    result = check_consonant_sequence(word)
    print(result)