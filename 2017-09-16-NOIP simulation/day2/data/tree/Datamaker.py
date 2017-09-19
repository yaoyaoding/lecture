#!/usr/bin/python

from random import *

prob = "tree"

cases = [   # (N,type)
        (10,1),
        (10,1),
        (100000,1),
        (100000,1),
        (100,10),
        (100,100),
        (100000,100),
        (100000,1000),
        (100000,10000),
        (100000,100000)
        ]
cur = 0
for (N,d) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    n = randint(N/2,N)
    cout += "%d\n" % n
    for i in range(2,n+1) :
        p = randint(max(1,i-d),i-1)
        cout += "%d %d\n" % (p, i)




##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

