values = []

for i in range(16):
    values.append(i)

print("-"*39)
print("|  decimal  |  octal  |  Hexadecimal  |")
print("-"*39)
for i in range(8):
    print(f"|      {values[i]}    |    {oct(values[i])[2:]}    |       {hex(values[i])[2:].upper()}       |")
for i in range(8, 10):
    print(f"|      {values[i]}    |   {oct(values[i])[2:]}    |       {hex(values[i])[2:].upper()}       |")
for i in range(10, 16):
    print(f"|     {values[i]}    |   {oct(values[i])[2:]}    |       {hex(values[i])[2:].upper()}       |")
print("-"*39)