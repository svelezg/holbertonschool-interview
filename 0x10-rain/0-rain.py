#!/usr/bin/python3
"""
contain the rain function
"""


def rain(walls):
    """
    calculate how much water will be retained after it rains.
    :param walls: list of non-negative integers
    :return: Integer indicating total amount of rainwater retained.
    """
    n = len(walls)
    rain = 0

    left_side = [0] * n
    left_side[0] = walls[0]
    for i in range(1, n):
        left_side[i] = max(left_side[i - 1], walls[i])

    right_side = [0] * n
    right_side[-1] = walls[-1]
    for i in range(n - 2, -1, -1):
        right_side[i] = max(right_side[i + 1], walls[i])

    for i in range(0, n):
        rain += min(left_side[i], right_side[i]) - walls[i]

    return rain
