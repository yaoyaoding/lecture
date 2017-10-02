#!/usr/bin/python

from random import *

prob = "fill"

cases = [   #(n,m,q)
        5,
        5,
        5,
        50,
        50,
        1000,
        1000,
        1000,
        1000,
        1000
        ]
cur = 0

def trans(a) :
    if a == 0 :
        return '.'
    else :
        return '#'

for (N) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    T = 10
    cout += "%d\n" % T
    print "N = ", N
    for t in range(T) :
        print "t = ", t
        n = randint((N+1) / 2, N)
        m = randint((N+1) / 2, N)
        c = randint(1, n * m)
        s = [ [ 0 for j in range(m) ] for i in range(n) ]
        sx = randint(0,n-1)
        sy = randint(0,m-1)
        s[sx][sy] = 1
        vc = [(sx,sy)]
        c = c - 1
        while c != 0 :
            (cx,cy) = choice(vc)
            (dx,dy) = choice([(0,1),(0,-1),(1,0),(-1,0)])
            cx = cx + dx
            cy = cy + dy
            if 0 <= cx and cx < n and 0 <= cy and cy < m and s[cx][cy] == 0:
                s[cx][cy] = 1
                vc.append((cx,cy))
                c = c - 1
        cout += "%d %d\n" % (n, m)
        for i in range(n) :
            cout += "".join( [ trans(s[i][j]) for j in range(m) ] )
            cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

