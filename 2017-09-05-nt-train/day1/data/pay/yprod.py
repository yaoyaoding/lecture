#!/usr/bin/python

from random import *
from math import *

prob = "pay"

cases = [   #(n,m,q)
        (1000,10000,2),
        (1000,10000,2),
        (100000,1000000000,1),
        (100000,1000000000,1),
        (100000,1000000000,1),
        (100000,1000000000,1),
        (100000,1000000000,2),
        (100000,1000000000,2),
        (100000,1000000000,2),
        (100000,1000000000,2),
        ]
cur = 0

def gcd(a,b) :
    if b == 0 :
        return a
    else :
        return gcd(b, a%b)

for (T,n,opt) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    cout += "%d %d\n" % (T, opt)
    for t in range(T) :
        a = randint(1,int(sqrt(sqrt(n))))
        b = randint(1,int(sqrt(sqrt(n))))
        d = gcd(a,b)
        c = 0
        if choice([True,True, True, True, False]) :
            c = randint(max(a,b) / d,n/d) * d
#            cout += "d = %d" % d
        else :
            c = randint(max(a,b),n)
        cout += "%d %d %d\n" % (a, b, c)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

