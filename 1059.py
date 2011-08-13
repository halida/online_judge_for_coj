#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1059
"""
#help codes
inp = raw_input

def getints():
    return [int(i)
            for i in raw_input().split(' ')
            if i]

def process():
    while True:
        d = getints()[0]
        if d == 0: break
        t = d
        out = []
        while t != 0:
            r = t % 2
            out.insert(0, r)
            t = t / 2
        parity = sum(out)
        display = ''.join([str(i) for i in out])
        print "The parity of %s is %d (mod 2)." % (display, parity)

process()


