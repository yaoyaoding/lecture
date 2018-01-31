#!/usr/bin/python

from random import *

prob = "sing"
cases = [ #(n,m)
        (10,10),
        (10,10),
        (10,10),
        (100000,500000),
        (100000,500000),
        (100000,500000),
        (100000,500000),
        (100000,500000),
        (100000,500000),
        (100000,500000),
        ];
cur = 0

for (n,m) in cases :
    cur += 1
    cout = ""
    print "making %d..." % cur
    ##-----------------------

    if n == 10 :
        edges = [
                ( 1, 2 ),
                ( 1, 3 ),
                ( 2, 3 ),
                ( 3, 1 ),
                ( 3, 4 ),
                ( 4, 5 ),
                ( 6, 7 ),
                ( 7, 8 ),
                ( 8, 9 ),
                ( 9, 10 )
                ];
        cout += "%d %d\n" % (n, m)
        for (u,v) in edges:
            cout += "%d %d\n" % (u,v)
    elif n == 10000 :
        cout += "%d %d\n" % (n,m)
        for i in range(m) :
            u = randint(1,n-1)
            v = randint(u+1,n)
            cout += "%d %d\n" % (u,v)
    elif n == 100000 :
        cout += "%d %d\n" % (n,m)
        tt = 100000
        for i in range(m-tt) :
            ub = randint(0,(n-1)/5-1)
            vb = randint(ub+1,(n-1)/5)
            u = randint( ub * 5 + 1, ub * 5 + 5 )
            v = randint( vb * 5 + 1, vb * 5 + 5 )
            cout += "%d %d\n" % (u,v)
        for i in range(tt) :
            b = randint(0,(n-1)/5)
            u = randint( b * 5 + 1, b * 5 + 5 )
            v = randint( b * 5 + 1, b * 5 + 5 )
            cout += "%d %d\n" % (u,v)

    ##-----------------------
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

