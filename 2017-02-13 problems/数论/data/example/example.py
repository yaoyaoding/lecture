#!/usr/bin/python

from random import *

prob = "example"

cases = [   #(n,m,q)
        (100,100,100),
        (250,250,250),
        (500,500,500),
        (1,500,100000),
        (1,500,100000),
        (1,500,100000),
        (500,500,100000),
        (500,500,100000),
        (500,500,100000),
        (500,500,100000)
        ]
cur = 0
for (n,m,q) in cases :
    cout = "%d %d %d\n" % (n, m, q)
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data



##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

