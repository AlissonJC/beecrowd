from datetime import datetime

birthdate = input().strip()

date = datetime.strptime(birthdate, "%d/%m")

pisces_start, pisces_end = datetime.strptime("19/02", "%d/%m"), datetime.strptime("20/03", "%d/%m")
aries_start, aries_end = datetime.strptime("21/03", "%d/%m"), datetime.strptime("20/04", "%d/%m")
taurus_start, taurus_end = datetime.strptime("21/04", "%d/%m"), datetime.strptime("20/05", "%d/%m")
gemini_start, gemini_end = datetime.strptime("21/05", "%d/%m"), datetime.strptime("20/06", "%d/%m")
cancer_start, cancer_end = datetime.strptime("21/06", "%d/%m"), datetime.strptime("22/07", "%d/%m")
lion_start, lion_end = datetime.strptime("23/07", "%d/%m"), datetime.strptime("22/08", "%d/%m")
virgo_start, virgo_end = datetime.strptime("23/08", "%d/%m"), datetime.strptime("22/09", "%d/%m")
libra_start, libra_end = datetime.strptime("23/09", "%d/%m"), datetime.strptime("22/10", "%d/%m")
scorpio_start, scorpio_end = datetime.strptime("23/10", "%d/%m"), datetime.strptime("21/11", "%d/%m")
sagittarius_start, sagittarius_end = datetime.strptime("22/11", "%d/%m"), datetime.strptime("21/12", "%d/%m")
capricorn_start_1, capricorn_end_1, capricorn_start_2, capricorn_end_2 = datetime.strptime("22/12", "%d/%m"), datetime.strptime("31/12", "%d/%m"), datetime.strptime("01/01", "%d/%m"), datetime.strptime("19/01", "%d/%m")
aquarius_start, aquarius_end = datetime.strptime("20/01", "%d/%m"), datetime.strptime("18/02", "%d/%m")

if pisces_start <= date <= pisces_end:
    print("peixes")
elif aries_start <= date <= aries_end:
    print("aries")
elif taurus_start <= date <= taurus_end:
    print("touro")
elif gemini_start <= date <= gemini_end:
    print("gemeos")
elif cancer_start <= date <= cancer_end:
    print("cancer")
elif lion_start <= date <= lion_end:
    print("leao")
elif virgo_start <= date <= virgo_end:
    print("virgem")
elif libra_start <= date <= libra_end:
    print("libra")
elif scorpio_start <= date <= scorpio_end:
    print("escorpiao")
elif sagittarius_start <= date <= sagittarius_end:
    print("sagitario")
elif capricorn_start_1 <= date <= capricorn_end_1 or capricorn_start_2 <= date <= capricorn_end_2:
    print("capricornio")
elif aquarius_start <= date <= aquarius_end:
    print("aquario")
elif pisces_start <= date <= pisces_end:
    print("peixes")