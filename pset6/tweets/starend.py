# for line in file:
#     if not line.startswith(";", line.endswith("\n")) or line.startswith(';') :
#         pos.add(line)
# file.close() #cirra file

import cs50

pos = set()
neg = set()

file_pos = open("posi.txt", "r")

for line in file_pos:
    if not line.startswith('\n') and not line.startswith(';'):
        pos.add(line.rstrip('\n'))
num1 = len(pos)
print("Numero final postivas", num1)
file_pos.close()

file_neg = open("nega.txt", "r")
for line in file_neg:
    if not line.startswith('\n') and not line.startswith(';'):
        neg.add(line.rstrip('\n'))
num2 = len(neg)
print("Numero final postivas", num2)
file_neg.close
print()


#########

print("Dame una palabra")
palabra = cs50.get_string()
print("tu palabra es", palabra)

if palabra in pos:
    print("Pos")
elif palabra in neg:
    print("neg")
else:
    print("Neutral")

########
# pr = [1,2,3,4]
# if 4 in pr:
#     print("si esta")

# print(pos)
# #ya esta pos metido
# check = cs50.get_string()
# if check.lower() in pos:
#     print("si esta")

# else:
#     print("No esta")


############
#listo ¡¡¡
#if num < 11 and (not line.startswith('\n') and (not line.startswith(';')) ):
# if not line.startswith('\n') and not line.startswith(';'):

###
# for line in file:
#     if line.islower():
#         pos.add(line)
#         print(line, end="")
# print()

############CONCLUSION FINAL#############
# for line in file:
#     if not line.startswith('\n') and not line.startswith(';'):