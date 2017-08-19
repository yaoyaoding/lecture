#!/usr/bin/python

from random import *
from math import *

prob = "island"

cases = [   #(n,m,q)
        10,
        10,
        10,
        100,
        100,
        100,
        100,
        100,
        100,
        100
        ]
cur = 0
for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    cout += "%d\n" % n
    L = 900
    for i in range(n) :
        rad = 1.0 * i / n * 2 * pi
        x = L * cos(rad)
        y = L * sin(rad)
        dx = uniform(1.0,5.0)
        dy = uniform(1.0,5.0)
        cout += "%.2f %.2f\n" % (x + dx, y + dy)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

