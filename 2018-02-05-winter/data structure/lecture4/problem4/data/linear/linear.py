#!/usr/bin/python

from random import *

prob = "linear"

cases = [   #
            100,
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
for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    M = 1000000007
    cout += "%d\n" % n
    for i in range(n) :
        cout += "%d " % randint(0,M-1)
    cout += "\n"
    cout += "%d\n" % n
    for i in range(n) :
        opt = choice([0, 1])
        if opt == 0 :
            l = randint(1, n)
            r = randint(l, n)
            cout += "modify %d %d %d %d\n" % (l, r, randint(0,M-1), randint(0,M-1))
        else :
            l = randint(1, n)
            r = randint(l, n)
            cout += "query %d %d\n" % (l, r)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

