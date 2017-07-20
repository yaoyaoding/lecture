#!/usr/bin/python

from random import *

prob = "redpacket"

cases = [   #(n,q,t,c)
        (1000,1000,0,1000),
        (1000,1000,0,1000),
        (1000,1000,0,1000),
        (100000,100000,1,7),
        (100000,100000,1,6),
        (100000,100000,1,5),
        (100000,100000,1,3),
        (100000,100000,1,1),
        (100000,100000,1,2),
        (100000,100000,1,1),
        ]
cur = 0
for (n,q,tp,cnt) in cases :
    cur += 1
    print "make %d..." % cur
    cout = ""
##-----
#TODO generate the data
    cout += "%d\n" % n
    for i in xrange(2,n+1) :
        p = 0
        if tp == 0 :
            p = randint(1, min(i-1,cnt))
        else :
            p = randint(max(i-cnt,1),i-1)
        cout += "%d %d\n" % (p, i)
    cout += "%d\n" % q
    for i in xrange(q) :
        opt = choice( ['give', 'single', 'all'] )
        if opt == 'give' :
            cout += "%s %d %d\n" % (opt, randint(1,n), randint(1,100000))
        else :
            cout += "%s %d\n" % (opt, randint(1,n))

##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

