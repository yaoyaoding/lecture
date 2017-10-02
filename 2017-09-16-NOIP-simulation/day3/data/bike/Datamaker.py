#!/usr/bin/python

from random import *

prob = "bike"

cases = [   #(n,m,q,s)
        8,
        8,
        8,
        8,
        8,
        8,
        64,
        64,
        64,
        64,
        256,
        256,
        256,
        256,
        256,
        256,
        256,
        256,
        256,
        256
        ]
cur = 0
for (N) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    n = randint(N/2,N)
    m = randint(n / 2 , 2 * n  )
    cout += "%d %d\n" % (n, m)
    for i in range(m) :
        cout += "%d %d %d\n" % (randint(1,n), randint(1,n), choice([0,1]))

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

