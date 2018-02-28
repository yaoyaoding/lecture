#!/usr/bin/python

from random import *

prob = "bit"

cases = [   #
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
for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d\n" % n
    for i in range(n) :
        cout += "%d " % randint(1,1000)
    cout += "\n"
    cout += "%d\n" % n
    for i in range(n) :
        opt = choice(["query", "modify"])
        if opt == "query" :
            cout += "query %d\n" % randint(1,n)
        else :
            l = randint(1,n)
            r = randint(l,n)
            d = randint(1,1000)
            cout += "modify %d %d %d\n" % (l, r, d)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

