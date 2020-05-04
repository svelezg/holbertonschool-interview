#include "binary_trees.h"

/**
 * height_recursion - function that calculates the height using recursion
 *
 * @tree: node to find recursion
 * Return: the number of height nodes
 */

size_t height_recursion(const binary_tree_t *tree)
{
size_t left_count = 0, right_count = 0;

if (tree->left)
	left_count = height_recursion(tree->left);
if (tree->right)
	right_count = height_recursion(tree->right);
return ((left_count > right_count) ? left_count + 1 : right_count + 1);
}

/**
 * binary_tree_balance - returns the height of a tree
 * @tree: is the node from which to get the node
 * Return: an integer with the height or 0 if node is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int left = 0, right = 0;

if (tree)
{
if (tree->left)
	left = height_recursion(tree->left);
if (tree->right)
	right = height_recursion(tree->right);
return (left - right);
}
else
return (0);
}

/**
 * binary_tree_is_full - checks if a tree is full.
 *
 * @tree: root node.
 * Return: 1 if full or 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
if (!tree)
	return (1);
if (!binary_tree_is_full(tree->left))
	return (0);
if (!binary_tree_is_full(tree->right))
	return (0);
if ((tree->left && !tree->right) || (!tree->left && tree->right))
	return (0);
return (1);
}


/**
 * binary_tree_is_perfect - Returns if the tree is perfect
 * @tree: is the node from which to get the node
 *
 * Return: 1 if is perfect, 0 if doesn't
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int isperfect_left = 1, isperfect_right = 1;

if (tree == NULL)
	return (0);
if (tree->left)
	isperfect_left = binary_tree_is_perfect(tree->left);
if (tree->right)
	isperfect_right = binary_tree_is_perfect(tree->right);
if (binary_tree_is_full(tree) && !binary_tree_balance(tree))
	return (isperfect_left * isperfect_right);
return (0);
}

/**
 * recursion_heap - performs the recursion for adding new nodes
 *
 * @node: root
 * @value: value of the new node
 * Return: pointer to the new node
 */
heap_t *recursion_heap(heap_t **node, int value)
{
heap_t *new_node_r = NULL, *new_node_l = NULL, *tmp;

if (*node == NULL)
{
*node = binary_tree_node(*node, value);
return (*node);
}
tmp = *node;
if (binary_tree_is_perfect(tmp) && !(tmp->parent))
{
while (tmp->left)
	tmp = tmp->left;
tmp->left = binary_tree_node(tmp, value);
return (tmp->left);
}
else if (tmp->left && !tmp->right)
{
tmp->right = binary_tree_node(tmp, value);
return (tmp->right);
}
else if (tmp->left && tmp->right && binary_tree_balance(tmp) == 1
		 && binary_tree_is_perfect(tmp->left))
{
tmp = tmp->right;
while (tmp->left)
	tmp = tmp->left;
tmp->left = binary_tree_node(tmp, value);
return (tmp->left);
}
if (tmp->left)
	new_node_l = recursion_heap(&(tmp->left), value);
if (tmp->right && !new_node_l)
	new_node_r = recursion_heap(&(tmp->right), value);
if (new_node_l)
	return (new_node_l);
else if (new_node_r)
	return (new_node_r);
return (NULL);
}

/**
 * heap_insert - inserts a value in a binary heap.
 *
 * @root: root of a tree.
 * @value: value to insert.
 * Return: The new node or null.
 */

heap_t *heap_insert(heap_t **root, int value)
{
heap_t *parent, *node, *son;

node = recursion_heap(root, value);
while (node && node->parent && node->n > node->parent->n)
{
	parent = node->parent;
	if (parent->right == node) /*node at its parent's right */
	{
		son = node->left, node->left = parent->left; /* node to parent left (1)*/
		if (parent->left)
			parent->left->parent = node; /* parent left to node (2)*/
		parent->left = son; /* parent and son (3)*/
		if (parent->left)
			parent->left->parent = parent; /* son to parent (4)*/
		son = node->right, node->right = parent; /* node to parent (5)*/
		parent->right = son; /* parent to son (6)*/
	}
	else /*node at its parent's left */
	{
		son = node->right, node->right = parent->right;
		if (parent->right)
			parent->right->parent = node;
		parent->right = son;
		if (parent->right)
			parent->right->parent = parent;
		son = node->left, node->left = parent;
		parent->left = son;
	}
	if (son)
		son->parent = parent; /* son to parent (7)*/
	node->parent = parent->parent; /* node and grandparent (8)*/
	if (parent->parent && parent->parent->right == parent)
		parent->parent->right = node; /* grandparent and node (9)*/
	else if (parent->parent)
		parent->parent->left = node;
	parent->parent = node; /* parent and node (10)*/
}
if (node && !node->parent)
	*root = node;
return (node);
}
