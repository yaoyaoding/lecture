#!/usr/bin/python

from random import *

prob = "modeq"

cases = [   #(top)
            5,
            10,
            100,
            1000,
            10000,
            100000,
            1000000,
            10000000,
            100000000,
            1000000000,
            1000000000,
        ]
cur = -1
for (n) in cases :
    cout = "1000\n"
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    for t in xrange(1000) :
        cout += "%d %d %d\n" % (
                choice( [ -1, 1 ] ) * randint(1,n),
                choice( [ -1, 1 ] ) * randint(1,n),
                choice( [ -1, 1 ] ) * randint(1,n) 
                )
##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

