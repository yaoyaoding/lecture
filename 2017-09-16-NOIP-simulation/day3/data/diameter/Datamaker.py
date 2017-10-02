#!/usr/bin/python

from random import *

prob = "diameter"

cases = [   #(n,m,q)
        (300,30,300),
        (300,40,300),
        (300,50,300),
        (2000,25,2000),
        (2000,100,2000),
        (100000,20,100000),
        (100000,300,100000),
        (100000,500,100000),
        (100000,1000,100000),
        (100000,5000,100000)
        ]
cur = 0
for (n,step,q) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    edges = []
    for s in range(0,n,step) :
        for i in range(1,min(step,n - s)) :
            edges.append( (s + i, s + randint(0, i - 1)) )
    cout += "%d %d %d\n" % (n, len(edges), q)
    for (u,v) in edges :
        cout += "%d %d\n" % (u+1, v+1)
    for i in range(q) :
        cout += "%d %d\n" % (randint(1,n), randint(1,n))

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

