#!/usr/bin/python

from random import *

prob = "kand"

cases = [   #(n,k,U)
        (10,5,(1<<3)-1),
        (100,44,(1<<4)-1),
        (100,55,(1<<5)-1),
        (100000,5324,(1<<15)-1),
        (100000,34234,(1<<15)-1),
        (100000,342,(1<<15)-1),
        (100000,3232,(1<<15)-1),
        (100000,328,(1<<20)-1),
        (100000,3232,(1<<20)-1),
        (100000,33,(1<<20)-1)
        ]
cur = 0
for (n,m,U) in cases :
    cout = "%d %d %d\n" % (n, m, randint(0,U))
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    for i in range(n) :
        cout += "%d " % randint(1,U)
    cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

