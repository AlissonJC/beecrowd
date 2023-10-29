def encrypt_message(message):
    shifted_message = ''.join([chr(ord(c) + 3) if c.isalpha() else c for c in message])

    reversed_message = shifted_message[::-1]

    half = len(reversed_message) // 2
    final_message = ''.join([chr(ord(c) - 1) if i >= half else c for i, c in enumerate(reversed_message)])

    return final_message

num_cases = int(input())

for _ in range(num_cases):
    line = input()
    encrypted_message = encrypt_message(line)
    print(encrypted_message)