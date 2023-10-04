values = []

for i in range(16):
    values.append(i)

print("---------------------------------------")
print("|  decimal  |  octal  |  Hexadecimal  |")
print("---------------------------------------")
for i in range(8):
    print(f"|      {values[i]}    |    {oct(values[i])[2:]}    |       {hex(values[i])[2:].upper()}       |")
for i in range(8, 10):
    print(f"|      {values[i]}    |   {oct(values[i])[2:]}    |       {hex(values[i])[2:].upper()}       |")
for i in range(10, 16):
    print(f"|     {values[i]}    |   {oct(values[i])[2:]}    |       {hex(values[i])[2:].upper()}       |")
print("---------------------------------------")