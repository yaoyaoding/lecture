#!/usr/bin/python

from random import *

n = 5
q = 5
print n
for i in range(n) :
    print randint(1,5), 
print
print q
for t in range(q) :
    opt = choice( ['query', 'modify'] )
    if opt[0] == 'q' :
        l = randint(1,n)
        r = randint(l,n)
        print opt, l, r
    else :
        l = randint(1,n)
        r = randint(l,n)
        d = randint(1,5)
        print opt, l, r, d

