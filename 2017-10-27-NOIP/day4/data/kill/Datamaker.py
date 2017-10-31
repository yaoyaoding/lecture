#!/usr/bin/python

from random import *

prob = "kill"

cases = [   #(n,m)
        (6,15),
        (5,17),
        (7,18),
        (9,19),
        (2,5000),
        (3,2000),
        (5000,5000),
        (50,100),
        (100,200),
        (1000,2000),
        (2500,5000)
        ]
cur = -1
for (n,m) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    bound = 1000000000
    s = randint(1,bound)
    cout += "%d %d %d\n" % (n, m, s)
    for i in range(n) :
        cout += "%d " % randint(1,bound)
    cout += "\n"
    for i in range(m) :
        cout += "%d " % randint(1,bound)
    cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

