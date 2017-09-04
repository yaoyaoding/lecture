#!/usr/bin/python

from random import *

prob = "surround"

cases = [   #(n,m,q)
        12,
        12,
        12,
        200,
        200,
        200,
        200,
        200,
        200,
        200
        ]
cur = 0
for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    T = 10
    cout += "%d\n" % T
    for t in range(T) :
        m = n / 2
        if n == 200 :
            m = n 
        cout += "%d %d\n" % (n, m)
        for i in range(n) :
            cout += "%.1f %.1f\n" % (uniform(0.0,1.0), uniform(0.0,1.0))
        for i in range(m) :
            cout += "%.1f %.1f\n" % (uniform(0.02,0.98), uniform(0.02,0.98))


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

