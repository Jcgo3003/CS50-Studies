import cs50

#Getting the right input
while True:
    print("Number: ", end="")
    n = cs50.get_string()
    if n.isdigit():
        break

#Getting number of 13, 15 and 16 digits long
if not (len(n) == 13 or len(n) == 15 or len(n) == 16):
    print("INVALID")

#If 13 or 15 long digit
if ( len(n) == 13 or len(n) == 15 ):
    num = int(len(n))
    #adding the right numbers
    sum_num_right = 0
    for i in range (1, num, 2):
        num_right = int(n[i]) * 2
        #Adding numbers bigger than 9
        if (num_right > 9):
            num_right= (int(num_right * 0.1)) + (num_right % 10)

        sum_num_right = sum_num_right + num_right
    #adding the left numbers
    sum_num_left  = 0
    for j in range (0, num, 2):
        num_left = int(n[j])
        sum_num_left = sum_num_left + num_left
###Getting all the numbers together
    total = sum_num_right + sum_num_left
    card_id = int(n[0])*10 + int(n[1])

    if (total%10 == 0 and ( int((card_id*0.1)) == 4 )):
        print("VISA")
    elif (total%10 == 0 and ( card_id == 34 or card_id == 37 )):
        print("AMEX")
    else:
        print("INVALID")

if (len(n) == 16):
    num = 16
    #Adding the right numbers
    sum_num_right = 0
    for i in range (0, 16, 2):
        num_right = int(n[i])* 2
        if (num_right > 9):
            num_right= (int(num_right * 0.1)) + (num_right % 10)

        sum_num_right = sum_num_right + num_right

    #Adding the left numbers
    sum_num_left  = 0
    for j in range (1, 16, 2):
        num_left = int(n[j])
        sum_num_left = sum_num_left + num_left

    #Getting all the numbers together
    total = sum_num_right + sum_num_left
    card_id = int(n[0])*10 + int(n[1])

    if total%10 == 0 and ( card_id > 50 or card_id < 56 ):
        print("MASTERCARD")
    else:
        print("INVALID")



