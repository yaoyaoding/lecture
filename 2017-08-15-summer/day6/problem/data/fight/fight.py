#!/usr/bin/python

from random import *

prob = "fight"

cases = [   #(n,m,q)
        5000,
        5000,
        5000,
        50000,
        50000,
        50000,
        50000,
        50000,
        50000,
        50000
        ]
cur = 0
for n in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d\n" % (n, n)
    for i in range(n) :
        cout += "%d %d %d\n" % (randint(0,30000), randint(0,30000), randint(150,200))
    for i in range(n) :
        cout += "%d %d %d\n" % (randint(0,30000), randint(0,30000), randint(0,1000000000))


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

