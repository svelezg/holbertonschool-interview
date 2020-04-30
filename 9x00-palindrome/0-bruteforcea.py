#!/usr/bin/env python3


def shortestPalindrome(s):

    n = len(s)
    if n < 2:
        return s
    rev = s[::-1]
    for i in range(n):
        print(i, s[:n-i], rev[i:])
        if s[:n-i] == rev[i:]:
            print('-->', rev[:i], s)
            res = rev[:i] + s
            print(len(res))
            return res
    return ""

s ='fcecfiaaf'
print(shortestPalindrome(s))
