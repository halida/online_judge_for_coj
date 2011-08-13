#!/usr/bin/env python
#-*- coding:utf-8 -*-
"""
module: 1004
"""
#help codes
inp = raw_input

def getints():
    return [int(i)
            for i in raw_input().split(' ')
            if i]

DIRS = [
    (1, 0),
    (0, 1),
    (-1, 0),
    (0, -1)
    ]
DIR_NAMES = 'RDLU'

def process():
    cases = getints()[0]
    for i in range(cases):
        M, N = getints()
        MAP = [[0] * N
               for i in range(M)]
        D = (1, 0)
        P = (0, 0)
        MAP[P[1]][P[0]] = 1
        turn_counter = 0
        while True:
            next = P[0] + D[0], P[1] + D[1]
            if turn_counter >= 4:
                break
            if (next[0] < 0 or
                next[0] >= N or
                next[1] < 0 or
                next[1] >= M or
                MAP[next[1]][next[0]] != 0):
                D = DIRS[(DIRS.index(D) + 1) % 4]
                turn_counter += 1
                continue
            
            MAP[next[1]][next[0]] = 1
            P = next
            turn_counter = 0
            
        print DIR_NAMES[DIRS.index(D)]

process()



