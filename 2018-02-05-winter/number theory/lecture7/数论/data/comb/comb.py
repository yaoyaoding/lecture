#!/usr/bin/python

from random import *

prob = "comb"

cases = [   #(n,p)
            (123,5),
            (123,5),
            (321,7),
            (997,13),
            (123456787654,1000000007),
            (123456787654,100000007),
            (123456787654,10627),
            (1234567854,941),
            (12345672387654,7057),
            (1234567878654,3),
            (12345678765884,7),
        ]
cur = -1
for (n,p) in cases :
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    
    cout = "%d %d\n" % (n,p)


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

