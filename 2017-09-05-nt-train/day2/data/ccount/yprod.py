#!/usr/bin/python

from random import *

prob = "ccount"

cases = [   #(n,m,q)
        (1,5000),
        (2,5000),
        (3,1000000000),
        (4,1000000000),
        (5,1000000000000000000),
        (6,1000000000000000000),
        (7,1000000000000000000),
        (8,1000000000000000000),
        (9,1000000000000000000),
        (10,1000000000000000000)
        ]
cur = 0
for (case,bound) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    T = 100
    cout += "%d\n" % T

    for t in range(T) :
        n = randint(1,bound)
        l = randint(0,n)
        if case == 3 or case == 4 :
            r = randint(l,min(l+1000,n))
        else :
            r = randint(l,n)
        cout += "%d %d %d\n" % (l, r, n)


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

