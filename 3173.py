from math import floor
from datetime import date, timedelta

jupiter = 11.9
saturn = 29.6

days = 365
date_in = date(2020, 12, 21)

revolutions = int(input())

leap_j = floor(jupiter * revolutions / 4)
leap_s = floor(saturn * revolutions / 4)

days_j = round(jupiter * revolutions * days + leap_j)
days_s = round(saturn * revolutions * days + leap_s)

date_j = date_in + timedelta(days_j)
date_s = date_in + timedelta(days_s)

print(f"Dias terrestres para Jupiter = {days_j}")
print(f"Data terrestre para Jupiter: {date_j}")
print(f"Dias terrestres para Saturno = {days_s}")
print(f"Data terrestre para Saturno: {date_s}")