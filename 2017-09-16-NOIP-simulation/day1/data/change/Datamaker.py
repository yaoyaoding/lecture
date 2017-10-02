#!/usr/bin/python

from random import *

prob = "change"

cases = [   
        10,
        10,
        10,
        100,
        100,
        100000,
        100000,
        100000,
        100000,
        100000
        ]
cur = 0

st = [1,2,5,10,20,50,100,200,500,1000,2000,5000,10000]

for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    tot = 0
    stt = []
    for a in st :
        for b in st :
            if b < a and a <= n :
                tot = tot + 1
                stt.append( (a,b) )
    cout += "%d\n" % tot
    for (a,b) in stt :
        cout += "%d %d\n" % (a, b)


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

