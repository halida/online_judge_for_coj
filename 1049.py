#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1049
"""
#help codes
inp = raw_input

def getints():
    return [int(i)
            for i in raw_input().split(' ')
            if i]

n = getints()[0]
print sum([i for i in range(1, n+1)])
