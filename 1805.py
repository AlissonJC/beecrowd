def sum_of_natural_numbers(A, B):
    sum_up_to_B = (B * (B + 1)) // 2

    sum_up_to_A_minus_1 = ((A - 1) * A) // 2 if A > 1 else 0

    result = sum_up_to_B - sum_up_to_A_minus_1

    return result

A, B = map(int, input().split())
result = sum_of_natural_numbers(A, B)
print(result)
