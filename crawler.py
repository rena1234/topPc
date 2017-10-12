from bs4 import BeautifulSoup
from urllib.request import urlopen
import math

def getLinks(page):
    """
        TODO
            retornar filtrado já, sem strings que comece com # ou /
                dica : ver expressões regulares
    """
    bsObj = BeautifulSoup(page.read(),'html.parser')
    return [ x.get('href') for x in bsObj.find_all('a') ]

class Node:
    
    def __init__(self, url, urlsApontadas):
        self.url = url
        self.urlsApontadas = urlsApontadas

    def printInfo(self):
        print("URL NÓ")
        print(self.url)
        print("URLS APONTADAS")
        for url in self.urlsApontadas:
            print(url)

"""
urls = [x.strip() for x in open(lista).readlines()]
"""

nodes = []
urls = [ 'https://google.com', 'https://facebook.com' ]

for url in urls:
    """
        TODO
            corrigir erro que o urlopen dá em algumas páginas
    """
    page = urlopen(url)
    nodes.append(Node(url,getLinks(page)))

"""
    TODO
        escrever as informacoes dos nós em um arquivo
            (primeiro tem que definir como vai ser o arquivo)
"""
