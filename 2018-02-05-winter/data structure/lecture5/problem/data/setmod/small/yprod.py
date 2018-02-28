#!/usr/bin/python

from random import *

n = 6
cout = ""
cout += "%d %d\n" % (n, n)
cout += " ".join( [ str(randint(1,n)) for i in xrange(n) ] )
cout += "\n"
for i in xrange(n) :
    opt = choice( [ "change", "modify", "query" ] )
    l = randint(1,n)
    r = randint(l,n)
    if opt == "query" :
        cout += "%s %d %d\n" % ( opt, l, r );
    else :
        x = randint(1,n)
        cout += "%s %d %d %d\n" % ( opt, l, r, x )
print cout
