#!/usr/bin/python3
"""contains the minOperations method"""


def candidate_range(n):
    cur = 5
    incr = 2
    while cur < n+1:
        yield cur
        cur += incr
        incr ^= 6  # or incr = 6-incr, or however
        "toggle between 2 and 4 increment (bitwise xor)"


def sieve(end):
    prime_list = [2, 3]
    sieve_list = [True] * (end+1)
    for each_number in candidate_range(end):
        if sieve_list[each_number]:
            prime_list.append(each_number)
            for multiple in range(each_number*each_number, end+1, each_number):
                sieve_list[multiple] = False
    return prime_list


def minOperations(n):
    """
    calculates fewest number of operations needed
    to result in exactly n H characters in the file.
    :param n: an integer
    :return: Returns an integer
    """
    if not isinstance(n, int) or n <= 1:
        return 0

    prime = sieve(n)

    res = 0
    fact = 1
    o = n
    while o > fact:
        for elem in prime:
            if n % elem == 0:
                fact *= elem
                res += elem
                n = n / elem
                break
    return res
