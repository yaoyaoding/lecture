#!/usr/bin/python

from random import *

n = 10
m = randint(n-1,n+n)
q = 1
s = randint(n-2,n+2)


cout = ""
cout += "%d %d %d\n" % (n, m, q)
for i in range(2,n + 1) :
    p = randint(1,i - 1)
    cout += "%d %d\n" % (p, i)
for i in range(m - n + 1) :
    u = randint(1,n-1)
    v = randint(u+1,n)
    cout += "%d %d\n" % (u, v)
K = s / q
for i in range(q) :
    k = randint(1,K)
    cout += "%d " % k
    for t in range(k) :
        u = randint(1,n)
        cout += "%d " % u
    cout += "\n"

print cout
