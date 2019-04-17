import sys
import cs50

if len(sys.argv) == 2:
    code = sys.argv[1]
    code_lenght = len(code)

    if code.isalpha():
        print("plaintext:")
        plain = cs50.get_string()

    else:
        print("error!")
        exit(0)

else:
    print("error!")
    exit(1)

#  At this point i sure that my Key is only alphabetic characters

print("ciphertext: ")

plain_l = len(plain)

for i in range ( str(plain) )

    if plain.isupper():
        s[i] =  (ord(s[i]) - 65)

