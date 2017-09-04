#!/usr/bin/python

from random import *
from math import *


prob = "area"

cases = [   #(n,m,q)
        1,
        1,
        1,
        2,
        2,
        50,
        50,
        50,
        50,
        50
        ]
cur = 0
for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    
    q = 10
    cout += "%d %d\n" % (n, q)
    for i in range(n) :
        a = uniform(0.1, 50.0)
        maxb = sqrt(4 * a * 45)
        b = uniform(-maxb,maxb)
        c = uniform((b * b) / (4 * a) + 0.1, 50.0)
        cout += "%.2lf %.2lf %.2lf\n" % (a, b, c)
    for i in range(q) :
        L = uniform(-50,45)
        R = uniform(L+0.2,50)
        cout += "%.2lf %.2lf\n" % (L, R)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

