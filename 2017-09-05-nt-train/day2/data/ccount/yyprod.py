#!/usr/bin/python

from random import *

T = 1
print T
for t in range(T) :
    n = randint(1,1000000000000000000)
    l = randint(0,n)
    r = randint(l,min(l+1000,n))
    print l, r, n


