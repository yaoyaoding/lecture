#!/usr/bin/python

from random import *

prob = "solar"

cases = [   #(n,nx,ny,nz)
        (2,10,10,10),
        (5,10,10,10),
        (5,10,9,8),
        (5,8,9,10),
        (100,907,947,967),
        (100,937,941,947),
        (100,971,967,953),
        (100,971,941,937),
        (100,1000,947,800),
        (100,900,981,875)
        ]
cur = 0
for (n,nx,ny,nz) in cases :
    cout = "%d %d %d %d\n" % (n, nx, ny, nz)
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    st = []
    for i in range(n):
        p = (randint(0,nx-1),randint(0,ny-1),randint(0,nz-1))
        while p in st :
            p = (randint(0,nx-1),randint(0,ny-1),randint(0,nz-1))
        st.append(p)
        cout += "%d %d %d %d " % (randint(1,n), p[0], p[1], p[2])
        cout += "%d %d %d\n" % (randint(1-nx,nx-1), randint(1-ny,ny-1), randint(1-nz,nz-1))


##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

