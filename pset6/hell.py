#importa blablabla
import html
import os
import plotly
import socket

#importa objetos
from twython import Twython
from twython import TwythonAuthError, TwythonError, TwythonRateLimitError

#define chart Positive  Negative  Neutral
def chart(positive, negative, neutral):
    """Return a pie chart for specified sentiments as HTML."""## regresa una tabla para los sentimientos especificados como HTML

    # offline plot ##   aqui te dice la bibliografia para saber a hacerlos
    # https://plot.ly/python/pie-charts/
    # https://plot.ly/python/reference/#pie
    figure = { #figura es igual
        "data": [###data
            {
                "labels": ["positive", "negative", "neutral"], # etiquetas positivo negativo
                "hoverinfo": "none",    ##hover info ninguna
                "marker": {##maker
                    "colors": [
                        "rgb(0,255,00)",
                        "rgb(255,0,0)",
                        "rgb(255,255,0)"## colores
                    ]###data
                }, # a todo esto vale!!!
                "type": "pie",
                "values": [positive, negative, neutral]
            }
        ],
        "layout": {###diseno
            "showlegend": True ###blablabla
            }
    }
    return plotly.offline.plot(figure, output_type="div", show_link=False, link_text=False)##regresa  figura | out put type div | show link text lint


#### get user timeline (usuario , cuenta = 200)
def get_user_timeline(screen_name, count=200):
    """Return list of most recent tweets posted by screen_name."""
    # regresa una lista con los tweets mas recientes posteados por "screen_name"


####################### Esta parte es solamete para proteger el programa de cualquier anomalia ###############
    # ensure count is valid ### cuenta 200 tweets  si no los hay envia error
    if count < 1 or count > 200:# si count menor que 1 o count mayor que 200----si la cuenta de tiempo va mas alla de 200
        raise RuntimeError("invalid count")## solo protege al programa si pasa mas de 200 segundos

    # ensure environment variables are set ### asegura que las varaibles de entorno estan puestas
    if not os.environ.get("API_KEY"): ###si  os.envion.get (api key) es FALSO
        raise RuntimeError("API_KEY not set")  ###explota de esta manera
    if not os.environ.get("API_SECRET"):    ## si os.environ.get (api secret) FALSO
        raise RuntimeError("API_SECRET not set")    # explota de la siguiente manera
##############################################################################################################

    # get screen_name's (or @screen_name's) most recent tweets
    # https://dev.twitter.com/rest/reference/get/users/lookup
    # https://dev.twitter.com/rest/reference/get/statuses/user_timeline
    # https://github.com/ryanmcgrath/twython/blob/master/twython/endpoints.py
    try:

        twitter = Twython(os.environ.get("API_KEY"), os.environ.get("API_SECRET"))

        user = twitter.lookup_user(screen_name=screen_name.lstrip("@"))
        if user[0]["protected"]:
            return None

        tweets = twitter.get_user_timeline(screen_name=screen_name, count=count)
        return [html.unescape(tweet["text"].replace("\n", " ")) for tweet in tweets]

########################## aqui va hacer manejo de excepciones ################
    try:
        ##twitter = twython (os.environ.get  obtener api_key, os.eviron.get api_secret
        twitter = Twython(os.environ.get("API_KEY"), os.environ.get("API_SECRET"))###twitter llama a tython( utilsa api_key, Api secret)


        ########### Aqui esta buscando al usuario y una vez que lo obtiene lo carga a 'user'###########
        # https://dev.twitter.com/rest/reference/get/users/lookup   ###    devuelve hasta 100 usuarios objeto
        #user = twitter.lookup_user( screen_name = screen_name.lstrip('@')= usuario = twitter.lookup_user ( nombre = nombre lstrip @)
        user = twitter.lookup_user(screen_name=screen_name.lstrip("@")) # Usuario twitter.lookup_user(screen_name=screen_name.lstrip('@')
        if user[0]["protected"]: ## si el usuario [0] esta protegido regresa nada
            return None## regresar nada

        ########## Aqui esta obteniendo los tweets del usuario #################
        # https://dev.twitter.com/rest/reference/get/statuses/user_timeline
        ## tweets = twitter.get_user_timeline( screen_name = screen_name, count = count
        tweets = twitter.get_user_timeline(screen_name=screen_name, count=count)# tweets = twitter.get_user_timeline( screen name screen name, cuenta)
        #regresa html.unescape ( tweet ["text"] . remplaza ( "\n", " " ) for tweet in tweets
        return [html.unescape(tweet["text"].replace("\n", " ")) for tweet in tweets]



############################## Aqui estan las excepciones ##############################
    except TwythonAuthError:### si excepcion TwythonAuthError hara un raise RuntimeError
        raise RuntimeError("invalid API_KEY and/or API_SECRET") from None #Forzando a la maquina a hacer un error

    except TwythonRateLimitError: #### si TwythonRateLimitError
        raise RuntimeError("you've hit a rate limit") from None  #aqui fuerza a la maquina a hacer un error

    except TwythonError:
        return None###Aqui regresa None nada nulo

######## Conclusiones ##########
# count si es el numero de tweets

#tengo que agregar exclude_replies para que no me devuelva las respuestas a los tweets
# se supone que para hacer get_timeline seria
# GET https://api.twitter.com/1.1/statuses/home_timeline.json
###aqui creo que entraria tokenizer porque get etc etc etc devuelve muchas parametros que no me son utiles solo necesito el texto

# def get_user_timeline(self, **params):
#         """Returns a collection of the most recent Tweets posted by the user
#         indicated by the ``screen_name`` or ``user_id`` parameters.


# >>> tknzr = TweetTokenizer(strip_handles=True, reduce_len=True)
# >>> s1 = '@remy: This is waaaaayyyy too much for you!!!!!!'
# >>> tknzr.tokenize(s1)
# [':', 'This', 'is', 'waaayyy', 'too', 'much', 'for', 'you', '!', '!', '!']