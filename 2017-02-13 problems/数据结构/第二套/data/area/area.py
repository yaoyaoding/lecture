#!/usr/bin/python

from random import *

prob = "area"

cases = [   #( n )
        100,
        100,
        100,
        100000,
        100000,
        100000,
        100000,
        100000,
        100000,
        100000,
        ]
cur = 0
for (n ) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d\n" % n
    for i in xrange(n) :
        x1 = randint(1,n)
        y1 = randint(1,n)
        x2 = randint(x1,n)
        y2 = randint(y1,n)
        cout += "%d %d %d %d\n" % (x1, y1, x2, y2)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

