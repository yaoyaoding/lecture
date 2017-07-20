#!/usr/bin/python

from random import *

prob = "rotinv"

cases = [   #( n )
        300,
        300,
        300,
        5000,
        5000,
        5000,
        1000000,
        1000000,
        1000000,
        1000000,
        ]
cur = 0
for ( n ) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d\n" % n
    cout += " ".join( [ str(randint(1,n)) for i in xrange(n) ] )

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

