#!/usr/bin/python

from random import *

prob = "array"

cases = [   #(n,q)
        (1000,1000),
        (1000,1000),
        (1000,1000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        (100000,100000),
        ]
cur = 0
for (n,q) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d\n" % n
    for i in xrange(n) :
        cout += "%d " % randint(1,1000000000)
    cout += "\n"
    cout += "%d\n" % q
    for i in xrange(1,q+1) :
        opt = choice( [ 'query', 'modify', 'back' ] )
        if opt == 'query' :
            cout += "%s %d" % (opt, randint(1,n))
        elif opt == 'modify' :
            cout += "%s %d %d" % (opt, randint(1,n), randint(1,1000000000))
        else : 
            cout += "%s %d" % (opt, randint(0,i-1))
        cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

