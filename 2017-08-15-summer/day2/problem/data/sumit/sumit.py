#!/usr/bin/python

from random import *

prob = "sumit"

cases = [   #(n,m,t)
        (100,100,0),
        (100,100,0),
        (100,100,0),
        (10000,10000,1),
        (10000,10000,1),
        (10000,10000,1),
        (10000000,10000000,0),
        (10000000,10000000,0),
        (10000000,10000000,0),
        (10000000,10000000,0)
        ]
cur = 0
for (n,m,t) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    T = randint(500,1000)
    cout += "%d\n" % T
    for t in range(T) :
        nn = randint(n/2,n)
        mm = randint(m/2,m)
        if t == 1 :
            mm = nn
        cout += "%d %d\n" % (nn, mm)




##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

