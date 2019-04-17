from flask import Flask, render_template
from enum import Enum
import cs50

app = Flask(__name__)


@app.route("/")
def template_test():

    class Operation(Enum):
        """Operations"""

        DELETED = 1
        INSERTED = 2
        SUBSTITUTED = 3

        def __str__(self):
            return str(self.name.lower())

    # Getting data
    print('entrada')
    l_a = 'CAT'
    i = len(l_a)

    print('se convertira a')
    l_b = 'ATE'
    j = len(l_b)

    # Creating the matrix
    matrix = [[0 for x in range(j+2)] for y in range(i+2)]
    matrix[0][0]= 0, None

    ####### Columns #######
    # Numbers
    count_i = 0
    for y in range( 1, i + 2 ):
        matrix [y][0] = count_i , None
        count_i += 1

    # Delition cost
    count_i = 0
    for y in range( 1, i + 2):
        matrix [y][1] = count_i , 1
        count_i += 1

    ####### Rows #######
    # Numbers
    count_j = 0
    for x in range( 1 , j + 2 ):
        matrix [0][x] = count_j , None
        count_j += 1

    # Insertions
    count_j = 0
    for x in range(1, j + 2):
        matrix [1][x] = count_j , 2
        count_j += 1

    #  AQUI SE ESCRIBE TODA LA RECURISVIDAD
    count_i = 2
    count_j = 2

    # while vertical
    y = 2
    while y < i + 2:

        # while horizotal
        x = 2
        while x < j + 2:

            # Evaluating sustitution
            b = 0
            if l_a[y-2] == l_b[x-2]:
                b = 0
            else:
                b = 1

            # Determining each operation value
            de = matrix[y-1][x][0] + 1
            ins = matrix [y][x-1][0] + 1
            sust = matrix[y-1][x-1][0] + b

            # Finding the minumal cost
            val = min( de, ins, sust  )

            #setting up operation into the matrix
            if de == val:
                matrix[y][x] = de , 'D'
            if sust == val:
                matrix[y][x] = sust, 'S'
            if ins == val:
                matrix[y][x] = ins, 'I'
            x += 1

        y += 1

    #################################   #################################   #################################
    # Extract operations from table
    operations = []
    i, j = len(l_a), len(l_b)
    while True:
        _, operation = matrix[i][j]
        if not operation:
            break
        if operation == Operation.INSERTED:
            j -= 1
        elif operation == Operation.DELETED:
            i -= 1
        else:
            i -= 1
            j -= 1
        operations.append(operation)
    operations.reverse()

    # Maintain list of intermediate strings, operation, and descriptions
    transitions = [(l_a, None, None)]
    i = 0

    # Apply each operation
    prev = l_a
    for operation in operations:

        # Update string and description of operation
        if operation == Operation.INSERTED:
            s = (prev[:i], l_b[i], prev[i:])
            description = f"inserted '{l_b[i]}'"
            prev = prev[:i] + l_b[i] + prev[i:]
            i += 1
        elif operation == Operation.DELETED:
            s = (prev[:i], prev[i], prev[i + 1:])
            description = f"deleted '{prev[i]}'"
            prev = prev[:i] + prev[i + 1:]
        elif prev[i] != l_b[i]:
            s = (prev[:i], l_b[i], prev[i + 1:])
            description = f"substituted '{prev[i]}' with '{l_b[i]}'"
            prev = prev[:i] + l_b[i] + prev[i + 1:]
            i += 1
        else:
            i += 1
            continue
        transitions.append((s, str(operation), description))
    transitions.append((l_b, None, None))


    return render_template('template.html', my_string="Hello world!", my_list=[0,1,2,3,4,5], matrix = matrix, operations=operations, operation=operation, s1=l_a, s2=l_b, l1=len(l_a),l2=len(l_b))


if __name__ == '__main__':
    app.run(debug=True)