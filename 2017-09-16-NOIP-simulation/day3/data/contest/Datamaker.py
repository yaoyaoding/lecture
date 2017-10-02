#!/usr/bin/python

from random import *

prob = "contest"

cases = [   #(n)
        (1,  4),
        (1,  4),
        (1,  4),
        (1,  4),
        (1,  4),
        (2,  4),
        (2,  4),
        (2,  4),
        (2,  4),
        (2,  4),
        (5,  10),
        (5,  10),
        (5,  10),
        (5,  10),
        (5,  10),
        (7,  10),
        (7,  10),
        (7,  10),
        (7,  10),
        (7,  10),
        (9,  10),
        (9,  10),
        (9,  10),
        (9,  10),
        (9,  10),
        (10, 30),
        (10, 30),
        (10, 30),
        (10, 30),
        (10, 30),
        (11, 30),
        (11, 30),
        (11, 30),
        (11, 30),
        (11, 30),
        (12, 30),
        (12, 30),
        (13, 30),
        (18, 30),
        (20, 30),
        (21, 30),
        (21, 30),
        (21, 30),
        (21, 30),
        (21, 30),
        (22, 30),
        (24, 30),
        (25, 30),
        (26, 30),
        (30, 30)
        ]
cur = 0
for (n,m) in cases :
    cout = ""
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data

    st = []
    cout += "%d\n" % n
    for i in range(n) :
        a = randint(0,m)
        while a in st :
            a = randint(0,m)
        st.append(a)
        cout += "%d " % a
    cout += "\n"


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

