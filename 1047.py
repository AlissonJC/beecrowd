h1, m1, h2, m2 = map(int, input().split())

hours_duration = 24 - h1 + h2

minutes_duration = 60 - m1 + m2

if hours_duration > 24:
    hours_duration -= 24

if m1 > m2:
    hours_duration -= 1

if hours_duration == 24 and minutes_duration > 0 and m1 != m2:
    hours_duration = 0

if minutes_duration >= 60:
    minutes_duration -= 60

print(f"O JOGO DUROU {hours_duration} HORA(S) E {minutes_duration} MINUTO(S)")