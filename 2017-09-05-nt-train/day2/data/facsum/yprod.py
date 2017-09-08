#!/usr/bin/python

from random import *

prob = "facsum"

cases = [   #(n,m,q)
        5000,
        5000,
        100000,
        100000,
        100000,
        10000000,
        10000000,
        10000000,
        10000000,
        10000000
        ]
cur = 0
for (bound) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    
    n = bound - randint(0,10)
    k = randint(1,10)
    cout += "%d %d\n" % (n, k)


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

