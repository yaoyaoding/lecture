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
    cout = "%d %d\n" % (n, q)
    for i in xrange(n) :
        cout += "%d " % randint(-100,100)
    cout += "\n"
    cur += 1
    print "make %d..." % cur
    for i in xrange(q) :
        opt = choice( ['query', 'modify'] )
        ln = n / 2 + randint(0, n / 2)
        l = randint(1, n - ln + 1)
        r = l + ln - 1
        if opt[0] == 'q' :
            cout += "%s %d %d\n" % (opt, l, r)
        else :
            d = randint(-100,100)
            cout += "%s %d %d %d\n" % (opt, l, r, d)
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

