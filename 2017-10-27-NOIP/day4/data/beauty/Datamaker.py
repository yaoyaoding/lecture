#!/usr/bin/python

from random import *

prob = "beauty"

cases = [   #(n,k,a)
        (333,10,0),
        (12331,6,0),
        (22321,6,1),
        (23214,10,0),
        (41231,10,0),
        (21111,10,1),
        (20000,10000,0),
        (30000,15000,0),
        (100000,10000,1),
        (100000,20000,0),
        (100000,30000,0)
        ]
cur = -1
for (n,k,a) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d %d\n" % (n, k, a)
    st = set()
    for i in range(2*k) :
        u = randint(1,n)
        while u in st :
            u = randint(1,n)
        st.add(u)
        cout += "%d " % u
    cout += "\n"
    if a == 1 :
        for i in range(2,n+1) :
            cout += "%d %d\n" % (i - 1, i)
    else :
        for i in range(2,n+1) :
            if choice([True,False,True,True,True]) :
                cout += "%d %d\n" % (randint(max(1,i-10),i-1), i)
            else :
                cout += "%d %d\n" % (randint(1,i-1), i)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

