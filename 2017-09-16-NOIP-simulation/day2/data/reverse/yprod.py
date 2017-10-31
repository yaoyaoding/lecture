#!/usr/bin/python

from random import *

prob = "reverse"

def arb() :
    return choice([True,False])

 
def B() :
    T = 3

    cout = ""
    cout += "%d\n" % T
    for t in range(T) :
        L = (t + 1) * 33
        if arb() :
            a = randint(L/2,L)
            b = randint(L/2,L)
            c = randint(1,min(a,b))
            sc = [choice("AB") for i in range(c)]
            sa = sc
            sb = sc
            for i in range(a - c) :
                if arb() :
                    sa.append("A")
                else :
                    sa.reverse();
                    sa.append("B")
            for j in range(b - c) :
                if not arb() :
                    sb.append("A")
                else :
                    sb.reverse()
                    sb.append("B")
            cout += "%s %s \n" % ("".join(sa), "".join(sb))
        else :
            a = randint(L/2,L)
            b = randint(L/2,L)
            sa = []
            sb = []
            for i in range(a) :
                sa.append(choice("AB"))
            for i in range(b) :
                sb.append(choice("AB"))
            cout += "%s %s\n" % ("".join(sa), "".join(sb))
    print cout
B()

