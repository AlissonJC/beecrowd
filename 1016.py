x_speed = 60
y_speed = 90

distance = int(input())

speed_diff = y_speed - x_speed

time = distance / speed_diff
time *= 60

print(f"{time:.0f} minutos")