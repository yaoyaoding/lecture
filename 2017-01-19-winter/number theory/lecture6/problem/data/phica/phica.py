#!/usr/bin/python

from random import *

prob = "phica"

cases = [   #(n)
        2,
        3,
        4,
        13,
        15,
        17,
        19,
        20,
        23,
        28,
        ]
cur = 0
for (n) in cases :
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout = "%d" % n


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

