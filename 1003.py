#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1003
"""
from testlib import *

#help codes
inp = raw_input

def getints():
    return [int(i)
            for i in raw_input().split(' ')
            if i]

def process():
    # get testcase
    cases = int(inp())
    for cases in range(cases):
        n, m = getints()
        scores = [0] * n
        for row in range(m):
            ragion_scores = getints()
            for i, s in enumerate(ragion_scores):
                scores[i] += s
        # output result
        print scores.index(max(scores)) + 1


IN = """
2 
3 3 
159 213 450 
512 890 993 
215 420 397 
2 5 
40 64 
35 12 
102 58 
43 15 
79 41
"""
OUT = """
3 
1
"""
