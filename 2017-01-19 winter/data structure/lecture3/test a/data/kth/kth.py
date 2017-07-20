#!/usr/bin/python

from random import *

prob = "kth"

cases = [   #(lbound,rbound,q)
        (1,1000,1000),
        (-400,400,1000),
        (-400,400,1000),
        (-100000/2+1,100000/2,100000),
        (-100000/2+1,100000/2,100000),
        (-100000/2+1,100000/2,100000),
        (-100000/2+1,100000/2,100000),
        (-100000/2+1,100000/2,100000),
        (-100000/2+1,100000/2,100000),
        (-100000/2+1,100000/2,100000),
    ]

aa = [ 0 for i in xrange(200000) ]
cur = 0
for (lbound,rbound,q) in cases :
    cur += 1
    print "make %d..." % cur
    cout = ""

    cout += "%d %d\n" % (lbound,rbound)
    cnt = 0
    for i in xrange(lbound,rbound+1) :
        aa[i] = k = randint(0,10)
        cnt += k
        cout += "%d " % k
    cout += "\n"
    cout += "%d\n" % q

    for i in xrange(q) :
        opt = choice( ['add', 'del', 'query'] )
        if opt[0] == 'q' :
            k = randint(1,cnt)
            cout += "%s %d\n" % (opt, k)
        elif opt[0] == 'd' :
            x = randint(lbound,rbound)
            if aa[x] != 0 :
                cnt -= 1;
                aa[x] -= 1;
            cout += "%s %d\n" % (opt, x)
        else :
            x = randint(lbound,rbound)
            aa[x] += 1;
            cnt += 1;
            cout += "%s %d\n" % (opt, x)
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

