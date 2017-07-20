#!/usr/bin/python

from random import *

prob = "derange"

cases = [   #(n,m,q)
            7,
            8,
            9,
            333,
            888,
            999,
            1000,
            66666,
            55555,
            99999,
        ]
cur = 0
for (n) in cases :
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    
    cout = "%d\n" % n


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

