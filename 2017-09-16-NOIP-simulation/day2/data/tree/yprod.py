#!/usr/bin/python

from random import *

prob = "tree"


cout = ""

n = 50
cout += "%d\n" % n
for i in range(2,n+1) :
    p = randint(max(1,i-2),i-1)
    cout += "%d %d\n" % (p, i)
print cout
