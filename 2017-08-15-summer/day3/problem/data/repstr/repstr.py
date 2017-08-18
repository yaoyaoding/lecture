#!/usr/bin/python

from random import *

prob = "repstr"

cases = [   #(n,m,q)
        15,
        15,
        15,
        20000,
        20000,
        20000,
        100000,
        100000,
        100000,
        100000,
        ]
cur = 0
for n in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    cout += "%d\n" % n
    cout += "".join([choice("ab??") for i in range(n)])



##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

