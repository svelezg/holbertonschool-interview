#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
} binary_tree_t;

/* print function */
void binary_tree_print(const binary_tree_t *);

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

/* 0. New node  */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* 1. Heap insert */
heap_t *heap_insert(heap_t **root, int value);

#endif /* HEAP_H */
