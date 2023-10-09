from operator import countOf

n = int(input())

values = []

for i in range(n):
    x = int(input())

    values.append(x)

values.sort()

count_array = []

for i in range(len(values)):
    if values[i] in count_array:
        pass
    else:
        print(f"{values[i]} aparece {countOf(values, values[i])} vez(es)")
        count_array.append(values[i])