import nltk
import cs50

#################
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
file_neg.close()

#########################

score = 0

sentence = cs50.get_string()
tokens = nltk.word_tokenize(sentence)
for line in tokens:
    print(line)
    if line.lower() in pos:
        score += 1
        print("pos")
    elif line.lower() in neg:
        score -= 1
        print("neg")
    else:
        print("neutral")

print()
print("Score =", score)

######### Conclusion ##########

score = 0

sentence = cs50.get_string()
tokens = nltk.word_tokenize(sentence)
for line in tokens:
    print(line)
    if line.lower() in pos:
        score += 1
        print("pos")
    elif line.lower() in neg:
        score -= 1
        print("neg")
    else:
        print("neutral")

print()
print("Score =", score)