texto = " hola est es una prueba necesito que la maquina encunetre 'text': 'cuando lo encuentre' quieroq que registre el siguiente tambien y el que sigue tambien 'text': 'Cuando esto pase queiro' que la maruin 'text': 'encuentre cada' unos de los textos que estan adentro de cada uno ellos"

print(texto.count("'text': "))
#cuento el numero de tweets
contador = texto.count("'text': ")

#getting the positions
sitio = [contador + 1]
sitio[0] = 0
cont = 0
sitio[cont] = 1
sitio[(int(cont)+1)] = 2

#un programa que vaya y encuentre los tweets
while contador != 0:
    if texto.find("'text':"):
        sitio[cont+1]  = int(texto.find("'text': ", sitio[cont]))
        cont += 1
        print(sitio)
        print('contador = ',contador)
        contador -= 1

print(sitio)


