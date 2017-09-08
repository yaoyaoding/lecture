#!/usr/bin/python

from random import *

prob = "facsum"

cases = [   #(n,m,q)
        ]
cur = 0
for (n,m,q) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data



##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

