#!/usr/bin/env python3
import heapq


def findKthNumber(m, n, k):
    """

    :param m: the height
    :param n: the length
    :param k: a positive integer
    :return: the k-th smallest number in this table
    """
    heap = [(i, i) for i in range(1, m + 1)]
    heapq.heapify(heap)  # create a heap from the list of smallest unused values in each row

    for i in range(k):
        print("{} iteration.".format(i + 1))
        print("current heap: {}".format(heap))
        val, root = heapq.heappop(heap)  # pop off the smallest value
        print("pop {} of row {}".format(val, root))
        print("heap after pop: {}".format(heap))
        next = val + root  # calculate the next smallest value in that row
        print("next-> {}".format(next))
        if next <= root * n:
            heapq.heappush(heap, (next, root))  # push the next value onto the heap
            print("push {} to row {}".format(next, root))
        print("**************")
    return val
