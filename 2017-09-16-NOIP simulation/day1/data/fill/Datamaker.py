#!/usr/bin/python

from random import *

prob = "fill"

cases = [   #(n,m,q)
        (12,30,12),
        (100000,100000,1),
        (100000,100000,1),
        (100000,100000,1),
        (100000,100000,1),
        (100000,100000,10),
        (100000,100000,100),
        (100000,100000,1000),
        (100000,100000,10000),
        (100000,100000,100000)
        ]
cur = 0
for (N,m,d) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    T = 3
    cout += "%d\n" % T
    for t in range(T) :
        n = randint(N/2,N)
        cout += "%d %d\n" % (n, m)
        for i in range(2,n+1) :
            cout += "%d %d\n" % (randint(max(1,i-d),i-1), i)
        for i in range(m) :
            cout += "%d %d\n" % (randint(1,n), randint(1,n))


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

