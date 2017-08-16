#!/usr/bin/python

from random import *

prob = "secret"

cases = [   #(n,m,q)
        (5,10),
        (5,10),
        (1000000,2000000000),
        (1000000,2000000000),
        (1000000,2000000000),
        (1000000,2000000000),
        (10000000,2000000000),
        (10000000,2000000000),
        (10000000,2000000000),
        (10000000,2000000000),
        ]
cur = 0
for (n,m) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    cout += "%d\n" % n
    mm = randint(m/2,m)
    a1 = randint(0,mm-1)
    c = randint(0,mm-1)
    d = randint(0,mm-1)
    cout += "%d %d %d %d\n" % (a1, c, d, m)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

