#!/usr/bin/python

from random import *

prob = "tcount"

cases = [   #(n,m)
        (12,12),
        (12,12),
        (12,12),
        (100,10000),
        (100,10000),
        (100,10000),
        (100,10000),
        (100,10000),
        (100,10000),
        (100,10000),
        ]
cur = 0
for (n,m) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    nn = 0
    if n == 12 :
        nn = 5
    else :
        nn = randint(n/4,n)
    mm = min(m,nn*(nn-1)/2)
    if mm > 12 :
        mm = randint(nn, mm)
    cout += "%d %d\n" % (nn, mm)
    e = []
    for i in range(mm) :
        u = randint(1,nn)
        v = randint(1,nn)
        while u == v or (u,v) in e or (v,u) in e :
            u = randint(1,nn)
            v = randint(1,nn)
        e.append((u,v))
        e.append((v,u))
        cout += "%d %d\n" % (u, v)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

