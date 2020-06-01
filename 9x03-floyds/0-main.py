#!/usr/bin/python3

find_duplicate = __import__('0-find_duplicate').find_duplicate


list_of_integers = [10, 4, 7, 8, 9, 3, 1, 6, 5, 2, 2]

duplicate = find_duplicate(list_of_integers)
print(duplicate)
