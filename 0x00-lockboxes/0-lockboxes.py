#!/usr/bin/python3
"""Contains the def canUnlockAll(boxes) function"""


def canUnlockAll(boxes):
    """determines if all the boxes can be opened"""

    num_boxes = len(boxes)
    keys = [0]

    for key in keys:
        box = boxes[key]
        for new_key in box:
            if new_key < num_boxes and new_key not in keys:
                keys.append(new_key)
    if num_boxes == len(keys):
        return True
    else:
        return False
