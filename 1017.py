consumption = 12

spent_time = int(input())
average_speed = int(input())

distance = spent_time * average_speed

liters_needed = distance / consumption

print(f"{liters_needed:.3f}")