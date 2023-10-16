x, y, z = map(int, input().split())

r = z/2

if x**2 == (y**2 + z**2):
    area = (y * z)/2 + (3 * r**2)/2
    print(f"AREA = {area:.0f}")
else:
    print("Nao eh retangulo!")