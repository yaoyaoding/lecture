#!/usr/bin/python

from random import *

prob = "count"

cases = [   #(n,m,q)
        (6,12,0),
        (6,12,0),
        (6,12,0),
        (100,1000,0),
        (100,1000,0),
        (100,1000,0),
        (100,1000,0),
        (100,1000,0),
        (100,1000,0),
        (100,1000,0)
        ]
cur = 0
for (n,m,opt) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d\n" % (n, m)
    R = 6
    if n == 100 :
        R = 10
    cw = [0 for i in range(m / R + 10) ]
    e = []
    for u in range(2,n+1) :
        w = randint(1,m / R)
        while cw[w] == 10 :
            w = randint(1,m / R)
        cw[w] = cw[w] + 1
        e.append((u - 1, u))
        e.append((u, u - 1))
        cout += "%d %d %d\n" % (u - 1, u, w)
    for i in range(m - n + 1) :
        w = randint(1,m / R)
        while cw[w] == 10 :
            w = randint(1,m / R)
        cw[w] = cw[w] + 1
        u = randint(1,n)
        v = randint(1,n)
        while u == v or (u,v) in e :
            u = randint(1,n)
            v = randint(1,n)
        e.append((u,v))
        e.append((v,u))
        cout += "%d %d %d\n" % (u, v, w)

        

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

