#!/usr/bin/python

from random import *

prob = "equation"

cases = [   #(n,m)
        (2,2),
        (2,3),
        (2,4),
        (80,100),
        (80,100),
        (80,100),
        (80,100),
        (80,100),
        (80,100),
        (80,100)
        ]
cur = 0
for (n,m) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    T = 10
    cout += "%d\n" % T
    for t in range(T):
        nn = randint(1,n)
        mm = randint(nn,nn+randint(0,3))
        aa = [ [ randint(-100000,100000)/100.0 for j in range(nn+1) ] for i in range(mm) ]
        for i in range(nn,mm) :
            opt = choice([0,1])
            if opt == 0 :
                aa[i] = aa[randint(0,nn-1)]
            else :
                aa[i] = [ randint(-100000,100000)/100.0 for j in range(nn+1) ]
        cout += "%d %d\n" % (nn, mm)
        for row in aa :
            for col in row :
                cout += "%.2f " % col
            cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

