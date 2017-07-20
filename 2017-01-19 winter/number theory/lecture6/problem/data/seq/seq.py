#!/usr/bin/python

from random import *

prob = "seq"

cases = [   #(n,m,q)
        1000000,
        1000000,
        1000000,
        1000000000000000000,
        1000000000000000000,
        1000000000000000000,
        1000000000000000000,
        1000000000000000000,
        1000000000000000000,
        1000000000000000000,
        ]
cur = 0
for (n) in cases :
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    cout = ""
    for i in range(8) :
        cout += "%d " % randint(0,n)
    cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

