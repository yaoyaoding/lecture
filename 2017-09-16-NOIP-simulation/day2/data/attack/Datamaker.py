#!/usr/bin/python

from random import *

prob = "attack"

cases = [   #(n,m,q,s)
        (7,10,20,100),
        (50000,49999,2000,100000),
        (50000,49999,5000,100000),
        (50000,49999,20000,100000),
        (50000,49999,30000,100000),
        (50000,50010,2000,100000),
        (50000,50100,5000,100000),
        (50000,51000,10000,100000),
        (50000,52000,20000,100000),
        (50000,53000,30000,100000),
        ]
cur = 0
for (n,m,q,s) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d %d\n" % (n, m, q)
    for i in range(2,n + 1) :
        p = randint(1,i - 1)
        cout += "%d %d\n" % (p, i)
    for i in range(m - n + 1) :
        u = randint(1,n-1)
        v = randint(u+1,n)
        cout += "%d %d\n" % (u, v)
    K = s / q
    for i in range(q) :
        k = randint(1,K)
        cout += "%d " % k
        for t in range(k) :
            u = randint(1,n)
            cout += "%d " % u
        cout += "\n"


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

