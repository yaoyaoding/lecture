#!/usr/bin/python

from random import *

prob = "rise"

cases = [   #(n)
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
    cout += " ".join( [ str(randint(1,n)) for i in xrange(n) ] )
    cout += "\n"
    for i in xrange(n) :
        l = randint(1,n)
        r = randint(l,n)
        cout += "%d %d\n" % (l, r)


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

