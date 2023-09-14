user_try = int(input())

password = 2002

while True:
    if user_try == password:
        print("Acesso Permitido")
        break
    else:
        print("Senha Invalida")
        user_try = int(input())