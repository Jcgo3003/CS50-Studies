import sys
import cs50

if len(sys.argv) == 2:
    k = sys.argv[1]
    y = len(k)

    for a in range (y):
        if k[a].isalpha() and k[a].isupper():
            k[a] = chr(ord(k[a]) - 65 )

        elif k[a].isalpha() and k[a].islower():
            k[a] = (chr(ord(k[a]) - 97))

        else:
            print("error!")
            exit(0)

else:
    print("error!")
    exit(1)

print("plaintext:")
s = cs50.get_string()
ss = len(s)
print("cihertext:")

for i in range (int(ss)):
    if s[i].isupper():
        s[i]= s[i] - 65
        upper = (s[i] + k[ j%y ]% 26)
        print("{}".format(upper + 65))

    elif s[i].islower():
        s[i] = s[i] - 97;
        lower = (s[i] + k[ j%y ]) % 26
        print("{}".format( lower + 97 ))

    else:
        print("{}".format(s[i]))

    print()
else:
    print("error!")
    exit(2)


