#!/usr/bin/python

from random import *

prob = "crt"

cases = [   #(n)
        3,
        2,
        2,
        3,
        3,
        3,
        4,
        4,
        4,
        4,
        4,
        ]
cur = -1
def gcd(a,b) :
    if b == 0 :
        return a;
    else :
        return gcd(b, a%b);
for (n) in cases :
    cout = "100000\n"
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    for t in xrange(100000) :
        cout += "%d\n" % n
        yes = choice( [ 1, 0 ] )
        v = randint(1,100000000)
        vc = []
        for i in range(n) :
            ok = False
            while not ok :
                m = randint(2,100)
                ok = True
                for mm in vc :
                    if gcd(mm,m) != 1 :
                        ok = False
            vc.append(m)
            cout += "%d %d\n" % (v % m, m)
##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

