#!/usr/bin/python

from random import *

prob = "setmod"

cases = [   #( n )
        30,
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
cur = -1
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
        opt = choice( [ "change", "modify", "query" ] )
        l = randint(1,n)
        r = randint(l,n)
        if opt == "query" :
            cout += "%s %d %d\n" % ( opt, l, r );
        else :
            x = randint(1,n)
            cout += "%s %d %d %d\n" % ( opt, l, r, x )

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

