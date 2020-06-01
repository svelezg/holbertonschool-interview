def find_duplicate(list_of_integers):
    # Find the intersection point of the two runners (tortoise and hare).
    tortoise = list_of_integers[0]
    hare = list_of_integers[0]
    print(tortoise, hare)
    while True:
        tortoise = list_of_integers[tortoise]
        hare = list_of_integers[list_of_integers[hare]]
        print(tortoise, hare)
        if tortoise == hare:
            print(tortoise)
            break
    print("***")

    # Find the "entrance" to the cycle.
    ptr1 = list_of_integers[0]
    ptr2 = tortoise
    print(ptr1, ptr2)
    while ptr1 != ptr2:
        ptr1 = list_of_integers[ptr1]
        ptr2 = list_of_integers[ptr2]
        print(ptr1, ptr2)
    return ptr1
