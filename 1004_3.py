#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1004_3
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
        N, M = getints()
        D = 3
        if M >= N:
            t = 2 * N - 1
        else:
            t = 2 * M
        print DIR_NAMES[(D + t) % 4]

process()
