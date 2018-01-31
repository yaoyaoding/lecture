#!/usr/bin/python

from random import *

prob = "chess"

cases = [   #(n,m,q,type)
        (3,4,1,1),
        (5,5,0,1),
        (5,10,0,1),
        (10,10,0,1),
        (15,15,20,0),
        (20,20,30,0),
        (25,25,100,0),
        (30,30,200,1),
        (30,30,300,1),
        (30,30,400,1),
        (30,30,500,1),
        ]
cur = -1
for (n,m,q,tp) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d %d %d\n" % (n, m, q, tp);
    st = set()
    for i in range(q) :
        x = randint(1,n)
        y = randint(1,m)
        if ((x,y) in st) :
            x = randint(1,n)
            y = randint(1,m)
        st.add((x,y))
        cout += "%d %d\n" % (x, y)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

