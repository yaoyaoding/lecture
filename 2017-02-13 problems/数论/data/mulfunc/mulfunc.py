#!/usr/bin/python

from random import *

prob = "mulfunc"

cases = [   # opt
        1,
        2,
        3,
        4,
        5,
        6,
        ]
cur = 0
for (opt) in cases :
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    cout = "%d" % opt
##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

