from bs4 import BeautifulSoup
from urllib.request import urlopen
import math

def getLinks(page):
    bsObj = BeautifulSoup(page.read(),'html.parser')
    return [ x.get('href') for x in bsObj.find_all('a') ]

class Node:
    
    def __init__(self, url, urlsApontadas):
        self.url = url
        self.urlsApontadas = urlsApontadas

    def printInfo(self):
        print(self.url)
        for url in self.urlsApontadas:
            print(url)
"""
page = urlopen('http://www.google.com')
bsObj = BeautifulSoup(page.read(),'html.parser')

for link in bsObj.find_all('a'):
    print(link.get('href'))
"""

"""
urls = [x.strip() for x in open(lista).readlines()]
"""

nodes = []
urls = [ 'https://google.com', 'https://facebook.com' ]
for url in urls:
    page = urlopen(url)
    nodes.append(Node(url,getLinks(page)))    
    inutil = math.cos(math.pi)

for node in nodes:
    node.printInfo()
