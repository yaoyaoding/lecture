#!/usr/bin/python

from random import *

prob = "matgcd"

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
    for i in xrange(n) :
        for j in xrange(m) :
            v = 2 * 2 * 2 * 3 * 3 * 3 * 7 * 7 * 7
            if( randint(1,10) == 1 ) :v /= 2;
            if( randint(1,100) == 1 ): v /= 2;
            if( randint(1,1000) == 1 ): v /= 2;
            if( randint(1,10000) == 1 ): v /= 2;
            if( randint(1,10) == 1 ) :v /= 3;
            if( randint(1,100) == 1 ): v /= 3;
            if( randint(1,1000) == 1 ) :v /= 3;
            if( randint(1,10) == 1 ) :v /= 7;
            if( randint(1,100) == 1 ): v /= 7;
            if( randint(1,1000) == 1 ): v /= 7;
            cout += str(v) + " "
        cout += "\n"
    for i in xrange(q) :
        opt = choice( ['query'] )
        x1 = randint(1,n)
        y1 = randint(1,m)
        x2 = randint(x1,n)
        y2 = randint(y1,m)
        cout += "%s %d %d %d %d\n" % (opt, x1, y1, x2, y2)
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

