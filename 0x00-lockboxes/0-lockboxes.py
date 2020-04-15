#!/usr/bin/python3
"""Contains the def canUnlockAll(boxes) function"""


def canUnlockAll(boxes):
    """determines if all the boxes can be opened"""

    length = len(boxes)
    keys = [0]

    for key in keys:
        box = boxes[key]
        for key in box:
            if key not in keys:
                keys.append(key)
    if length == len(keys):
        return True
    else:
        return False
