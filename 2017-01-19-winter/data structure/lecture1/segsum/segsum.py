#!/usr/bin/python

from random import *

prob = "segsum"

cases = [   #(n,q)
        (100,100),
        (500,500),
        (1000,1000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        ]
cur = 0
for (n,q) in cases :
    cout = "%d\n" % (n)
    for i in xrange(n) :
        cout += "%d " % randint(-100000,100000)
    cout += "\n"
    cur += 1
    print "make %d..." % cur
    cout += "%d\n" % q
    for i in xrange(q) :
        opt = choice( ['query', 'modify'] )
        if opt[0] == 'q' :
            l = randint(1,n)
            r = randint(l,n)
            cout += "%s %d %d\n" % (opt, l, r)
        else :
            l = randint(1,n)
            r = randint(l,n)
            d = randint(-100000,100000)
            cout += "%s %d %d %d\n" % (opt, l, r, d)
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

