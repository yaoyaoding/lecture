#!/usr/bin/python

from random import *

prob = "reverse"

cases = [   #(N,a,b)
        (1000,0,0),
        (10**5,0,0),
        (10**5,0,0),
        (10**18,1,1),
        (2**64-1,1,1),
        (10**18,0,1),
        (2**64-1,0,1),
        (10**18,1,0),
        (2**64-1,1,0),
        (10**18,0,0),
        (2**64-1,0,0),
        ]
cur = -1
for (N,a,b) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    T = 50
    cout += "%d %d %d\n" % (T, a, b)
    for t in range(T) :
        if t == 0 and N == 2**64 - 1 and b != 1 :
            cout += "%d %d\n" % (1, N)
        else :
            L = 0
            R = 0
            if b == 1 :
                R = 10**randint(1,18)
            else :
                R = randint(1,N)
            if a == 1 :
                L = 1
            else :
                L = randint(1,R)
            cout += "%d %d\n" % (L, R)


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

