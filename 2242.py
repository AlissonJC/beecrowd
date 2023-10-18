def vowel(l):
    return l in ['a', 'e', 'i', 'o', 'u']

word = input()

only_vowels = ''.join(list(filter(vowel, word)))
reversed_ = only_vowels[::-1]

print('S' if only_vowels == reversed_ else 'N')