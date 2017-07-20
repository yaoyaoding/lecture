#!/usr/bin/python

from random import *

prob = "seqmod"

cases = [   #( )
        1000,
        1000,
        1000,
        100000,
        100000,
        100000,
        100000,
        100000,
        100000,
        100000
        ]
cur = 0
for ( n ) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d\n" % (n, n)
    for i in xrange(2,n+1) :
        cout += "%d %d %d\n" % ( randint(max(1,i-3),i-1), i, randint(0,9) )
    for i in xrange(n) :
        u = randint( 1, n )
        v = randint( 1, n )
        while u == v :
            u = randint( 1, n )
            v = randint( 1, n )
        cout += "%d %d\n" % ( u, v )

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

