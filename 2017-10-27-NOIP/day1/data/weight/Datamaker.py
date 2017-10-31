#!/usr/bin/python

from random import *

prob = "bike"

cases = [   #(n,m,a)
        (25,50,0),
        (100,100,0),
        (1000,1000,0),
        (10000,10000,0),
        (30000,100000,1),
        (50000,100000,1),
        (70000,100000,1),
        (10000,100000,0),
        (30000,100000,0),
        (50000,100000,0),
        (70000,100000,0)
        ]
cur = -1
for (n,m,a) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

