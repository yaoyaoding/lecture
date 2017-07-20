#!/usr/bin/python

from random import *

prob = "matsum"

cases = [   #(n,m,q)
        (100,100,100),
        (250,250,250),
        (500,500,500),
        (1,10000,10000),
        (1,50000,50000),
        (1,100000,100000),
        (500,500,10000),
        (500,500,100000),
        (1000,1000,10000),
        (1000,1000,100000)
        ]
cur = 0
for (n,m,q) in cases :
    cout = "%d %d %d\n" % (n, m, q)
    cur += 1
    print "make %d..." % cur
    for i in xrange(q) :
        opt = choice( ['query', 'modify'] )
        if opt[0] == 'q' :
            x1 = randint(1,n)
            y1 = randint(1,m)
            x2 = randint(x1,n)
            y2 = randint(y1,m)
            cout += "%s %d %d %d %d\n" % (opt, x1, y1, x2, y2)
        else :
            x = randint(1,n)
            y = randint(1,m)
            d = randint(-100,100)
            cout += "%s %d %d %d\n" % (opt, x, y, d)
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

