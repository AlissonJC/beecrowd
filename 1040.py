n1, n2, n3, n4 = map(float, input().split())

w1, w2, w3, w4 = 2, 3, 4, 1

average = (n1*w1 + n2*w2 + n3*w3 + n4*w4)/10

if average >= 7.0:
    print(f"Media: {average:.1f}")
    print("Aluno aprovado.")
elif average < 5.0:
    print(f"Media: {average:.1f}")
    print("Aluno reprovado.")
elif 5.0 <= average <= 6.9:
    exam_score = float(input())
    new_average = (average + exam_score)/2
    if new_average >= 5.0:
        print(f"Media: {average:.1f}")
        print("Aluno em exame.")
        print(f"Nota do exame: {exam_score:.1f}")
        print("Aluno aprovado.")
        print(f"Media final: {new_average:.1f}")
    elif new_average < 4.9:
        print(f"Media: {average:.1f}")
        print("Aluno em exame.")
        print(f"Nota do exame: {exam_score:.1f}")
        print("Aluno reprovado.")
        print(f"Media final: {new_average:.1f}")