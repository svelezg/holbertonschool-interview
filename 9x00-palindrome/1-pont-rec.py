#!/usr/bin/env python3


def shortestPalindrome(s):

    n = len(s)
    if n < 2:
        return s
    i = 0
    for j in range(n - 1, -1, -1):
        if s[i] == s[j]:
            i += 1
    if i == n:
        return s
    rev = s[n-1:i-1:-1]
    return rev + shortestPalindrome(s[:i]) + s[i:]
