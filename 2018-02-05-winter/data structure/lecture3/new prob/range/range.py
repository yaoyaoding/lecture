#!/usr/bin/python

from random import *

prob = "range"

cases = [   # n
        30,
        1000,
        1000,
        1000,
        100000,
        100000,
        100000,
        100000,
        100000,
        100000,
        100000
        ]
cur = -1
for n in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d\n" % n
    for u in range(2,n+1) :
        cout += "%d %d\n" % (randint(max(1,u-10), u-1), u)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

