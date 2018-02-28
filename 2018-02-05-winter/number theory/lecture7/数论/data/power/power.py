#!/usr/bin/python

from random import *

prob = "power"

cases = [   #(n,m,q)
            5,
            6,
            18,
            18,
            1000,
            1000,
            1000,
            1000,
            100000,
            100000,
            100000
        ]
digits = "0123456789"
cur = -1
for (n) in cases :
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    
    cout = "".join( [ choice(digits) for t in range(n) ] )

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

