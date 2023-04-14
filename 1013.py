# Make a program that reads 3 integer values and present the greatest one
# followed by the message "eh o maior".

a, b, c = input().split()

a = int(a)
b = int(b)
c = int(c)

greatest_ab = (a+b+abs(a-b))/2

greatest_final = int((c + greatest_ab+abs(c-greatest_ab))/2)

print(f"{greatest_final} eh o maior")