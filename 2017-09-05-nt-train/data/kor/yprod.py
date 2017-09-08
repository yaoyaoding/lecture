#!/usr/bin/python

from random import *

prob = "kor"

cases = [   #(n,k,U)
        (10,5,(1<<3)-1),
        (100,22,(1<<4)-1),
        (100,19,(1<<5)-1),
        (100000,132,(1<<15)-1),
        (100000,169,(1<<15)-1),
        (100000,213,(1<<15)-1),
        (100000,149,(1<<15)-1),
        (100000,174,(1<<20)-1),
        (100000,189,(1<<20)-1),
        (100000,33,(1<<20)-1)
        ]
cur = 0
for (n,m,U) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    T = 5
    cout += "%d\n" % T
    for t in range(T) :
        s = randint(0,U)
        cout += "%d %d %d\n" % (n, m + randint(-4,4), s)
        for i in range(n - 1) :
            cout += "%d " % randint(0,U)
        cout += "%d\n" % s

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

