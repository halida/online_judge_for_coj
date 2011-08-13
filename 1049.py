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
if n > 0:
    print (n + 1) * n / 2
else:
    print -((-n + 1) * (-n) / 2 ) + 1
