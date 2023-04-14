age_in_days = int(input())

years = age_in_days // 365
age_in_days -= years * 365
months = age_in_days // 30
age_in_days -= months * 30
days = age_in_days

print(f"{years} ano(s)")
print(f"{months} mes(es)")
print(f"{days} dia(s)")