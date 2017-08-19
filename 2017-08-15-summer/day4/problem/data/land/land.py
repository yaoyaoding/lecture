#!/usr/bin/python

from random import *

prob = "land"

cases = [   #(n,m,q)
        10,
        10,
        10,
        1000,
        1000,
        1000,
        1000,
        1000,
        1000,
        1000
        ]
cur = 0
for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    cout += "%d\n" % n
    for i in range(n) :
        x1 = randint(-100000,100000) / 100.0
        y1 = randint(-100000,100000) / 100.0
        x2 = randint(-100000,100000) / 100.0
        y2 = randint(-100000,100000) / 100.0
        cout += "%lf %lf %lf %lf\n" % (x1, y1, x2, y2)



##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

