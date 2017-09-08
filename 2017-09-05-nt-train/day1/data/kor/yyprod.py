#!/usr/bin/python

from random import *

T = 5
print T
for t in range(T) :
    n = randint(5,10)
    U = (1<<randint(1,5)) - 1
    s = randint(0,U)
    print n, randint(1,n), s
    for i in range(n - 1) :
        print randint(0,U),
    print s

