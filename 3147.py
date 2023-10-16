h, e, a, o, w, x = map(int, input().split())

if h+e+a+x+1 > o+w:
    print("Middle-earth is safe.")
else:
    print("Sauron has returned.")