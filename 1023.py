#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1023
"""
#help codes
inp = raw_input

def getints():
    return [int(i)
            for i in raw_input().split(' ')
            if i]

def getfloats():
    return [float(i)
            for i in raw_input().split(' ')
            if i]

def process():
    result = 0.0
    for i in range(12):
        d = getfloats()[0]
        result += d
    print "%.2f" % round(result/12.0, 2)

process()

