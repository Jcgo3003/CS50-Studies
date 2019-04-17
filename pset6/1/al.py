import sys
import cs50

if len(sys.argv) == 2:
    code = sys.argv[1]
    code_l = len(code)

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
j = 0
for i in range (plain_l):

    if plain.isupper():
        temp_u = ord(plain()) - 65
        print(temp_u, end="")
        # temp_u2 = temp_u + ord(code ( j % code_l))%26
        # print("{}".format(chr(temp_u2 + 65)), end="")
        # j += 1

    elif plain.islower():
        temp_l = ord(plain()) - 97
        print(temp_l, end="")
        # temp_l2 = int(temp_l) + ord(code[ j % int(code_l)]) % 26
        # print("{}".format(chr(temp_l2 + 97)), end="")
        # j += 1

    else:
        print(" ", end="")

print()

#print("{}". format(chr(ord(plain[i]) - 65)))

