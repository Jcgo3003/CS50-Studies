import cs50

print("Number: ", end="")
n = cs50.get_string()

# solo para recordar
print(len(n))

if not (len(n)) == (13 or 15 or 16):
    print("INVALID")

elif (len(n)) == 13:
    num0 = n[1] * 2
    if (num0 > 9):
        num0 = num0[0] + num0[1]

    num1 = n[3] * 2
    if  (num1 > 9):
        num1 = num1[0] + num1[1]

    num2 = n[5] * 2
    if  (num2 > 9):
        num2 = num2[0] + num2[1]

    num3 = n[7] * 2
    if  (num3 > 9):
        num3 = num3[0] + num3[1]

    num4 = n[9] * 2
    if  (num4 > 9):
        num4 = num4[0] + num4[1]

    num5 = n[11] * 2
    if  (num5 > 9):
        num5 = num5[0] + num5[1]

    num6 = n[13] * 2
    if  (num6 > 9):
        num6 = num6[0] + num6[1]

    num7 = n[0] + n[2] + n[4] + n[6] + n[8] + n[10] + n[12]

    final = num0 + num1 + num2 + num3 + num4 + num5 + num6 + num7

    if ((final%2) == 0 and n[0] == 4):
        print("VISA")
    else:
        print("INVALID")

elif ((len(n)) == 15):

    num0 = n[1] * 2
    if  (num0 > 9):
        num0 = num0[0] + num0[1]

    num1 = n[3] * 2
    if  (num1 > 9):
        num1 = num1[0] + num1[1]

    num2 = n[5] * 2
    if  (num2 > 9):
        num2 = num2[0] + num2[1]

    num3 = n[7] * 2
    if  (num3 > 9):
        num3 = num3[0] + num3[1]

    num4 = n[9] * 2
    if  (num4 > 9):
        num4 = num4[0] + num4[1]

    num5 = n[11] * 2
    if  (num5 > 9):
        num5 = num5[0] + num5[1]

    num6 = n[13] * 2
    if  (num6 > 9):
        num6 = num6[0] + num6[1]

    num7 = n[15] * 2
    if  (num7 > 9):
        num7 = num7[0] + num7[1]

    num8 = n[0] + n[2] + n[4] + n[6] + n[8] + n[10] + n[12] + n[14]

    card_id = (n[0] * 10) + n[1]

    final = num0 + num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8
    if ( (final%2) == 0 and (card_id == 34 or card_id == 37) ):
        print("AMEX")

    else:
        print("INVALID")


elif (len(n)) == 16:
    num0 = n[0] * 2
    if  (num0 > 9):
        num0 = num0[0] + num0[1]

    num1 = n[2] * 2
    if  (num1 > 9):
        num1 = num1[0] + num1[1]

    num2 = n[4] * 2
    if  (num2 > 9):
        num2 = num2[0] + num2[1]

    num3 = n[6] * 2
    if  (num3 > 9):
        num3 = num3[0] + num3[1]

    num4 = n[8] * 2
    if  (num4 > 9):
        num4 = num4[0] + num4[1]

    num5 = n[10] * 2
    if  (num5 > 9):
        num5 = num5[0] + num5[1]

    num6 = n[12] * 2
    if  n(um6 > 9):
        num6 = num6[0] + num6[1]

    num7 = n[14] * 2
    if  (num7 > 9):
        num7 = num7[0] + num7[1]

    num8 = n[1] + n[3] + n[5] + n[7] + n[9] + n[11] + n[13] + n[15]

    card_id = (n[0] * 10) + n[1]

    if ((final%2) == 0 and n[0] == 4):
        print("VISA")

    elif ( (final%2) == 0 and ( card_id > 49 and card_id <56) ):
        print("MASTERCARD")

    else:
        print("INVALID")

