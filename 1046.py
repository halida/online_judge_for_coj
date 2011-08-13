#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1046
"""
#help codes
inp = raw_input

def getints():
    return [int(i)
            for i in raw_input().split(' ')
            if i]

def process():
    cases = getints()[0]
    for i in range(cases):
        a, b = getints()
        s = 0
        for j in range(a, b+1):
            s += j * (j+1) * (j+2)
            s %= 100
        print s

process()



