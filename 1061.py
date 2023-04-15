from datetime import timedelta

word_1, day_1 = input().split()
h1, m1, s1 = input().split(" : ")
word_2, day_2 = input().split()
h2, m2, s2 = input().split(" : ")

t1 = timedelta(days=int(day_1), hours=int(h1), minutes=int(m1), seconds=int(s1))
t2 = timedelta(days=int(day_2), hours=int(h2), minutes=int(m2), seconds=int(s2))

t3 = t2 - t1

hour = t3.seconds // 3600
seconds = t3.seconds % 3600
minutes = seconds // 60

seconds = seconds % 60

print(f"{t3.days} dia(s)")
print(f"{hour} hora(s)")
print(f"{minutes} minuto(s)")
print(f"{seconds} segundo(s)")