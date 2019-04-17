#!/usr/bin/env python3

import nltk#para obtener los tweets
import html#para hacer render
import os#para llamar al sistema???
import plotly# NI IDEA
import socket# NI IDEA
import sys#SITEMA????

from twython import Twython##para importar twython
from twython import TwythonAuthError, TwythonError, TwythonRateLimitError# y sus mensajes de error
from analyzer import Analyzer#mandar llamar anyliser
from nltk.tokenize import TweetTokenizer#tweet tokennizer
from termcolor import colored#colorear los tweets

def main():

    # Ensure proper usage ##promt para obtener del usuario
    if len(sys.argv) != 2:
        sys.exit("Usage: ./tweets user")

    # Setting up screen_name and count
    screen_name = sys.argv[1]
    print(screen_name)
    count = 10
    API_KEY = 'P6hCYrRhyKiCYtpR58grTj1bp'
    API_SECRET = 'bKWdo9g9MaZi2OYHHSGacFRELUwmG1JhGvf3rG562J11VKDGd5'

    # # ensure environment variables are set  #cuidar el programa
    # if not os.environ.get("API_KEY"):
    #     raise RuntimeError("API_KEY not set")
    # if not os.environ.get("API_SECRET"):
    #     raise RuntimeError("API_SECRET not set")

    # Ensure getting 50 tweets  # sacar 50 tweets
    if count < 1 or count > 10:
        raise RuntimeError("invalid count")
        sys.exit("invalid count")

    try:
        # Setting up environment variables # obtengo las enviroment claves
        twitter = Twython( API_KEY , API_SECRET )

        # Look up for the user # creo que aqui busca a los usurios para estar seguroo que la cuenta no es privada
        user = twitter.lookup_user(screen_name=screen_name.lstrip("@"))##usurio sera esto
        if user[0]["protected"]:#para proteger el programa aqui esta tomando el User[0] como el que queremos
            return None
            sys.exit("Private account")

        # Getting the tweets #aqui estoy obteniendo los tweets
        tweets = twitter.get_user_timeline(screen_name = screen_name , count = count, exclude_replies = True)

        for i in range ( 0, count):
            print(tweets[i]['text'])


        # print('Primero')
        # print(tweets[0])
        # print()
        # print('Segundo')
        # print(tweets[1])
        # print()
        # print('tercero')
        # print(tweets[2])
        # print()

        # print('Cuarto')
        # print(tweets[3])

        # tw = json.loads(tweets[0])
        # print(tw['text'])

        # print(tweets['text'])

        # tw = json.loads(tweets)
        # print(tw['text'])
        ## esta funcion tiene que ver con limpiar lo que me da en tweets


        # print(tweets)
        # print()




        # for line in file_pos:
        #     if not line.startswith('\n') and not line.startswith(';'):
        #         self.positives.add(line.rstrip('\n'))
        # file_pos.close()


        # Initailize analizer
        # tknzr = TweetTokenizer(strip_handles=True, reduce_len=True)
        # token = tknzr.tokenize(tweets)

        # # Analyze tweets #######

        # # absolute paths to lists
        # positives = os.path.join(sys.path[0], "positive-words.txt")
        # negatives = os.path.join(sys.path[0], "negative-words.txt")

        # # instantiate analyzer #alimentando analizer
        # analyzer = Analyzer(positives, negatives)

        # # analyze tweets
        # score = 0
        # for word in token:
        #     score += analyzer.analyze(token)



        # if score > 0.0:
        #     print(token ,colored(":)", "green"))
        # elif score < 0.0:
        #     print(token ,colored(":(", "red"))
        # else:
        #     print(token ,colored(":|", "yellow"))




 ######       return [html.unescape(tweet["text"].replace("\n", " ")) for tweet in tweets]#aqui no se porque llamo HTML################
#########################   Exepciones  #################################
    except TwythonAuthError:
        raise RuntimeError("invalid API_KEY and/or API_SECRET") from None
        sys.exit("invalid API_KEY and/or API_SECRET")
    except TwythonRateLimitError:
        raise RuntimeError("you've hit a rate limit") from None
        sys.exit("you've hit a rate limit")
    except TwythonError:
        sys.exit("Twython Error")
        return None

if __name__ == "__main__":
    main()
# export API_KEY=P6hCYrRhyKiCYtpR58grTj1bp
# export API_SECRET=bKWdo9g9MaZi2OYHHSGacFRELUwmG1JhGvf3rG562J11VKDGd5
# tknzr = TweetTokenizer(strip_handles=True, reduce_len=True)