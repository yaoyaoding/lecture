#!/usr/bin/python

from random import *

prob = "weight"

cases = [   #(n,m,a)
        (25,50,0),
        (100,100,0),
        (1000,1000,0),
        (10000,10000,0),
        (30000,100000,1),
        (50000,100000,1),
        (70000,100000,1),
        (10000,100000,0),
        (30000,100000,0),
        (50000,100000,0),
        (70000,100000,0)
        ]
cur = -1
for (n,m,a) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d %d\n" % (n, m, a)
    bound = 0
    if a == 1 :
        bound = 1
    else :
        bound = 1000000000
    edges = set()
    for i in range(m) :
        (u,v) = (randint(1,n),randint(1,n))
        while u == v or (u,v) in edges :
            (u,v) = (randint(1,n),randint(1,n))
        edges.add((u,v))
        edges.add((v,u))
        cout += "%d %d %d\n" % (u, v, randint(1,bound))

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

