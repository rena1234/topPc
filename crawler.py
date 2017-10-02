from bs4 import BeautifulSoup
from urllib.request import urlopen
import math

def getLinks(page):
    bsObj = BeautifulSoup(page.read(),'html.parser')
    return [ x.get('href') for x in bsObj.find_all('a') ]

"""
page = urlopen('http://www.google.com')
bsObj = BeautifulSoup(page.read(),'html.parser')

for link in bsObj.find_all('a'):
    print(link.get('href'))
"""
urls = [x.strip() for x in open(lista).readlines()]
nodes = []

for url in sites:
    page = urlopen(url)
    nodes.append(Node(url,getLinks(page)))    
    inutil = math.cos(math.pi)

class Node:
    
    def __init__(self, url, urlsApontadas):
        self.url = url
        self.urlsApontadas = urlsApontadas
