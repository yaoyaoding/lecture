#!/usr/bin/python

from random import *

prob = "crt"

cases = [   #(n)
        2,
        2,
        3,
        3,
        3,
        4,
        4,
        4,
        4,
        4,
        ]
cur = 0
for (n) in cases :
    cout = "100000\n"
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    for t in xrange(100000) :
        cout += "%d\n" % n
        yes = choice( [ 1, 0 ] )
        v = randint(1,100000000)
        if yes != 0 :
            for i in range(n) :
                m = randint(2,100)
                cout += "%d %d\n" % (v % m, m)
        else :
            for i in range(n) :
                m = randint(2,100)
                cout += "%d %d\n" % ( (v + choice( [ 1, 0 ] )) % m, m)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

