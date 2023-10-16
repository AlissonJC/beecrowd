while True:
    try:
        n = int(input())
        books = []
        for i in range(n):
            book = input()
            books.append(book)
        books.sort()
        for i in range(len(books)):
            print(books[i])
    except EOFError:
        break