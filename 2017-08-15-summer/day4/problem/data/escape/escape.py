#!/usr/bin/python

from random import *
from math import *

prob = "escape"

cases = [   #(n,m,q)
        10,
        10,
        10,
        1000,
        1000,
        1000,
        1000,
        1000,
        1000,
        1000
        ]
cur = 0

def dist(x1,y1,x2,y2) :
    dx = x1 - x2
    dy = y1 - y2
    return sqrt(dx * dx + dy * dy);
def middle(p1,p2) :
    k = randint(1,9) / 10.0
    x = p1[0] + k * (p2[0] - p1[0])
    y = p1[1] + k * (p2[1] - p1[1])
    return (x,y)

for (n) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    rads = [ uniform(0,pi+pi) for i in range(n) ]
    rads.sort()
    nn = 0
    pts = []
    for r in rads :
        length = uniform(0,1000.0)
        x = length * cos(r)
        y = length * sin(r)
        if len(pts) == 0 or dist(x,y,pts[-1][0],pts[-1][1]) > 1e-1 :
            pts.append((x,y))
            nn = nn + 1
    q = n
    cout += "%d %d\n" % (nn, q)
    for (x,y) in pts :
        cout += "%.2f %.2f\n" % (x, y)
    for i in range(q - 2) :
        cout += "%.2f %.2f\n" % (uniform(-1000.0,1000.0),uniform(-1000.0,1000.0))
    cout += "%.2f %.2f\n" % (pts[0][0], pts[0][1])
    cout += "%.2f %.2f\n" % middle(pts[0], pts[1])

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

