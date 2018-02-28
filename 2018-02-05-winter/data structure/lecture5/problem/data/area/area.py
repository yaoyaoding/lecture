#!/usr/bin/python

from random import *

prob = "area"

cases = [   #(n,top)
        (30,30),
        (1000,1000),
        (1000,1000),
        (1000,1000),
        (1000,1000000000),
        (1000,1000000000),
        (1000,1000000000),
        (1000,1000000000),
        (1000,1000000000),
        (1000,1000000000),
        (1000,1000000000),
        ]
cur = -1
for (n,top) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    
    cout += "%d\n" % n;
    for i in xrange(n) :
        x1 = randint(1,top)
        x2 = randint(x1,top)
        y1 = randint(1,top)
        y2 = randint(y1,top)
        cout += "%d %d %d %d\n" % (x1, y1, x2, y2)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

