#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1099
"""
#help codes
inp = raw_input

def getints():
    return [int(i)
            for i in raw_input().split(' ')
            if i]

def process():
    while True:
        data = getints()
        if len(data) == 1: break
        M = max(data)
        data.pop(data.index(M))
        if M * M == (data[0] ** 2 + data[1] ** 2):
            print "right"
        else:
            print "wrong"


process()
