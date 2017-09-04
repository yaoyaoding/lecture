#!/usr/bin/python

from random import *
from math import *

prob = "fish"

cases = [   #(n,m,q)
        50,
        50,
        50,
        200,
        200,
        2000,
        2000,
        2000,
        2000,
        2000
        ]
cur = 0
for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    
    cout += "%d\n" % n
    rads = []
    for i in range(n) :
        rad = uniform(0,2*pi)
        length = randint(100000-20,100000+20)
        cout += "%.0f %.0f\n" % (length * cos(rad), length * sin(rad))

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

