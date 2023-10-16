while True:
    try:
        cpf = input()

        a1 = int(cpf[0])
        a2 = int(cpf[1])
        a3 = int(cpf[2])
        a4 = int(cpf[4])
        a5 = int(cpf[5])
        a6 = int(cpf[6])
        a7 = int(cpf[8])
        a8 = int(cpf[9])
        a9 = int(cpf[10])

        prod_b1 = a1 * 1 + a2 * 2 + a3 * 3 + a4 * 4 + a5 * 5 + a6 * 6 + a7 * 7 + a8 * 8 + a9 * 9
        prod_b2 = a1 * 9 + a2 * 8 + a3 * 7 + a4 * 6 + a5 * 5 + a6 * 4 + a7 * 3 + a8 * 2 + a9 * 1

        b1 = 0
        b2 = 0

        if prod_b1 % 11 == 10:
            b1 = 0
        else:
            b1 = prod_b1 % 11

        if prod_b2 % 11 == 10:
            b2 = 0
        else:
            b2 = prod_b2 % 11

        if b1 != int(cpf[-2]) or b2 != int(cpf[-1]):
            print("CPF invalido")
        else:
            print("CPF valido")
    except EOFError:
        break