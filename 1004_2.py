#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1004_2
"""
#help codes
inp = raw_input

def getints():
    return [int(i)
            for i in raw_input().split(' ')
            if i]

DIR_NAMES = 'RDLU'

def process():
    cases = getints()[0]
    for i in range(cases):
        M, N = getints()
        D = 3
        S = True
        while M>0 and N>0:
            if S:
                M -= 1
            else:
                N -= 1
            S = not S
            D = (D + 1) % 4
        
        print DIR_NAMES[D]

process()




