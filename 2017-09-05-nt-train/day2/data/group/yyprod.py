#!/usr/bin/python

from random import *

def gcd(a,b) :
    if b == 0 :
        return a
    else :
        return gcd(b,a%b)

T = 10
print T
for t in range(T) :
    a = randint(1,1000)
    m = randint(1,1000)
    while gcd(a,m) != 1 :
        a = randint(1,1000)
        m = randint(1,1000)
    print a, m


