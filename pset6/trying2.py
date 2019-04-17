while True:
    try:
        x = int( input("dame un numero:"))
        break
    except ValueError:
        print("Error escribe un maldito numero")