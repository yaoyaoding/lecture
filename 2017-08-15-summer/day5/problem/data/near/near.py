#!/usr/bin/python

from random import *
from math import *

prob = "near"


cases = [   #(n,q,type)
        (1000,100,0),
        (1000,100,1),
        (1000,100,1),
        (1000,100,2),
        (1000,100,2),
        (10000,3000,2),
        (10000,3000,2),
        (10000,3000,2),
        (10000,3000,2),
        (10000,3000,2)
        ]
cur = 0
for (n,q,opt) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    bd = 10000000
    T = 10
    if n == 10000 :
        T = 2
    cout += "%d\n" % T
    for t in range(T) :
        cout += "%d\n" % n
        pts = [(0,0), (0, 1)]
        cout += "%d %d\n" % (0, 0)
        cout += "%d %d\n" % (0, 1)
        for i in range(n - 2) :
            x = randint(-bd,bd)
            y = randint(-bd,bd)
            while (x,y) in pts :
                x = randint(-bd,bd)
                y = randint(-bd,bd)
            pts.append((x,y))
            cout += "%d %d\n" % (x, y)
        m = 10
        cout += "%d\n" % m
        for i in range(m) :
            if opt == 0 :
                b = 4
                cout += "%d\n" % b
                cout += "%d %d\n" % (-bd, -bd)
                cout += "%d %d\n" % (bd, -bd)
                cout += "%d %d\n" % (bd, bd)
                cout += "%d %d\n" % (-bd, bd)
            elif opt == 1 :
                b = randint(10,20)
                rads = []
                for j in range(b) :
                    rads.append(uniform(0,2 * pi))
                rads.sort()
                ok = []
                for r in rads :
                    if len(ok) == 0 or abs(ok[-1] - r) > 1e-1 :
                        ok.append(r)
                length = randint(10,bd)
                cout += "%d\n" % len(ok)
                for r in ok :
                    cout += "%.0f %.0f\n" % (length * cos(r), length * sin(r))
            else :
                b = randint(10,20)
                rads = []
                for j in range(b) :
                    rads.append(uniform(0,2 * pi))
                rads.sort()
                ok = []
                for r in rads :
                    if len(ok) == 0 or abs(ok[-1] - r) > 1e-1 :
                        ok.append(r)
                cout += "%d\n" % len(ok)
                for r in ok :
                    length = randint(10,bd)
                    cout += "%.0f %.0f\n" % (length * cos(r), length * sin(r))
            cout += "%d\n" % q
            for i in range(q) :
                cout += "%d %d\n" % (randint(-bd,bd), randint(-bd,bd))
##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

