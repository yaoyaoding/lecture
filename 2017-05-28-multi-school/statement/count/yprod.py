#!/usr/bin/python

from random import *

prob = "count"
cases = [ #(n,m)
        (100000,1000),
        (100000,5000),
        (100000,10000),
        (1000000000,1000),
        (1000000000,5000),
        (1000000000,10000),
        (1000000000,50000),
        (1000000000,100000),
        (1000000000,100000),
        (1000000000,100000),
        ];
cur = 0

for (n,m) in cases :
    cur += 1
    cout = ""
    print "making %d..." % cur
    ##-----------------------

    st = set()
    cout += "%d %d\n" % (n,m)
    for i in xrange(m) :
        p = randint(1,n-1)
        while p in st :
            p = randint(1,n-1)
        st.add(p)
    lst = list(st)
    lst.sort()
    for x in lst :
        cout += "%d " % x
    cout += "\n"

    ##-----------------------
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

