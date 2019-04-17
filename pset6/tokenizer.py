import nltk
import os
import sys


from nltk.tokenize import TweetTokenizer
from analyzer import Analyzer


tknzr = TweetTokenizer()
s0 = "This is a cooool #dummysmiley: :-) :-P <3 and some arrows < > -> <--"

print(tknzr.tokenize(s0))
print()

tknzr = TweetTokenizer(strip_handles=True, reduce_len=True)
s1 = "This is a cooool #dummysmiley: :-) :-P <3 and some arrows < > -> <--"
print(tknzr.tokenize(s1))

# absolute paths to lists
positives = os.path.join(sys.path[0], "positive-words.txt")
negatives = os.path.join(sys.path[0], "negative-words.txt")

# instantiate analyzer
analyzer = Analyzer(positives, negatives)

a = tknzr.tokenize(s1)
score = 0
for word in a:
    print(word)
    score = analyzer.analyze(a)
    print(score)
