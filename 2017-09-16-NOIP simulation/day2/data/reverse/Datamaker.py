#!/usr/bin/python

from random import *

prob = "reverse"

cases = [   # 
        6,
        12,
        12,
        1000,
        1000,
        1000,
        1000,
        1000,
        1000,
        1000
        ]
cur = 0

def arb() :
    return choice([True,False])

for L in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    T = 20

    cout += "%d\n" % T
    for t in range(T) :
        if arb() :
            a = randint(L/2,L)
            b = randint(L/2,L)
            c = randint(1,min(a,b))
            sc = [choice("AB") for i in range(c)]
            sa = sc
            sb = sc
            for i in range(a - c) :
                if arb() :
                    sa.append("A")
                else :
                    sa.reverse();
                    sa.append("B")
            for j in range(b - c) :
                if arb() :
                    sb.append("A")
                else :
                    sb.reverse()
                    sb.append("B")
            cout += "%s %s \n" % ("".join(sa), "".join(sb))
        else :
            a = randint(L/2,L)
            b = randint(L/2,L)
            sa = []
            sb = []
            for i in range(a) :
                sa.append(choice("AB"))
            for i in range(b) :
                sb.append(choice("AB"))
            cout += "%s %s\n" % ("".join(sa), "".join(sb))
##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

