import sys
import cs50

print("hola")
s = cs50.get_string

for i in range(0, 5):
    s[i] = (chr(ord(s[i]) + 1))

print("{}".format(s))


