import cs50

while True:
    print("Number: ", end="")
    n = cs50.get_string()
    if n.isdigit():
        break

for i in range (int(n)):
    print("{}".format(i))