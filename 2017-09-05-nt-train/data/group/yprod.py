#!/usr/bin/python

from random import *

prob = "group"


def gcd(a,b) :
    if b == 0 :
        return a
    else :
        return gcd(b,a%b)

cases = [   #(n,m,q)
        1000,
        1000,
        1000,
        2000000000,
        2000000000,
        2000000000,
        2000000000,
        2000000000,
        2000000000,
        2000000000
        ]
cur = 0
for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    T = 1000
    cout += "%d\n" % T
    for t in range(T) :
        a = randint(1,n)
        m = randint(1,n)
        while gcd(a,m) != 1 :
            a = randint(1,n)
            m = randint(1,n)
        cout += "%d %d\n" % (a, m)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

