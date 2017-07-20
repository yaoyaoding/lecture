#!/usr/bin/python

from random import *

prob = "intkth"

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
        cout += "%d " % randint(1,n)
    cout += "\n"
    cout += "%d\n" % q
    for t in xrange(q) :
        opt = choice( [ 'query', 'modify' ] )
        if opt == 'query' :
            l = randint(1,n)
            r = randint(l,n)
            k = randint(1,r-l+1)
            cout += "%s %d %d %d" % (opt, l, r, k)
        else :
            cout += "%s %d %d" % (opt, randint(1,n), randint(1,n))
        cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

