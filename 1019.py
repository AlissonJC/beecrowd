duration = int(input())

hours = duration // 3600
duration -= hours * 3600
minutes = duration // 60
duration -= minutes * 60
seconds = duration

print(f"{hours:.0f}:{minutes:.0f}:{seconds:.0f}")
