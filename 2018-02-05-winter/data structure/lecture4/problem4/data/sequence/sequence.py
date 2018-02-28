#!/usr/bin/python

from random import *

prob = "sequence"

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

    oo = 100000000
    cout += "%d %d\n" % (n, n)
    for i in range(n) :
        cout += "%d " % randint(-oo,oo)
    cout += "\n"
    curlen = n
    for i in range(n) :
        opt = choice(['D', 'Q'])
        if opt == 'D' :
            cout += "D %d\n" % randint(1,curlen)
            curlen = curlen - 1
        else :
            cout += "Q %d\n" % randint(1,curlen)


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

