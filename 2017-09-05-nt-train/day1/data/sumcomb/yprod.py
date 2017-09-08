#!/usr/bin/python

from random import *

prob = "sumcomb"

cases = [   #(n,m,q)
        (1,5000),
        (2,5000),
        (3,5000),
        (4,1000000),
        (5,1000000),
        (6,1000000),
        (7,1000000),
        (8,1000000),
        (9,1000000),
        (10,1000000)
        ]
cur = 0
for (kase,bound) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    T = 50000
    if kase <= 3 :
        T = 1000
    cout += "%d\n" % T
    if kase == 9 or kase == 10 :
        T = T - 1
    for t in range(T) :
        n = randint(1,bound)
        m = 0
        if choice([1,1,1,1,1,2]) == 1 :
            m = randint(1,n)
        else :
            m = randint(1,bound)
        cout += "%d %d %d\n" % (choice([1,2]), n, m)
    if kase == 9 or kase == 10 :
        cout += "2 1 2\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

