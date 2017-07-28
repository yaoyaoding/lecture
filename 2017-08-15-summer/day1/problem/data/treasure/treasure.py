#!/usr/bin/python

from random import *

prob = "treasure"

cases = [   #(n,k)
        (1000,[1933]),
        (50000,[53087]),
        (50330,[53087]),
        (1000000000000000000,[3299]),
        (1000000000000000000,[53087]),
        (1000000000000000000,[1933]),
        (1000000000000000000,[6553]),
        (1000000000000000000,[2,3,11,53,40357,41117]),
        (1000000000000000000,[3,13,773,1009,41351]),
        (1000000000000000000,[3,13,773,1009,41507,41203]),
        ]
cur = 0
for (a,b) in cases :
    aa = a
    bb = randint(0,aa)
    cout = "%d %d %d\n" % (aa, bb, len(b))
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    for i in b :
        cout += "%d " % i
    cout += "\n"


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

