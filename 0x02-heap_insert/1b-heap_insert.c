/**
 * heap_insert - inserts a value in a binary heap.
 *
 * @root: root of a tree.
 * @value: value to insert.
 * Return: The new node or null.
 */

heap_t *heap_insert(heap_t **root, int value)
{
heap_t *tmp, *new_node, *current;

/* traverse the heap from top to bottom and insert new node at end */
new_node = recursion_heap(root, value);

/* going bottom to top exchange inserted node with the node above if it is greater than it */
while (new_node && new_node->parent && new_node->n > new_node->parent->n)
{
	/* tmp node to new_node-> parent */
	tmp = new_node->parent;

	*/ when the new node happens to ne to the right of its parent */
	if (tmp->right == new_node)
	{
		current = new_node->left /* pointer to former left of new_node */
		new_node->left = tmp->left;  */ redirect new_node left to former parent left
		if (new_node->left)
			new_node->left->parent = new_node; /* redirect left son parent to new_node */
		tmp->left = current; /* redirect former parent left son to former left son of new node */
		if (tmp->left)
			tmp->left->parent = tmp;  /* redirect left son parent of new_node to former parent */
		current = new_node->right,
		new_node->right = tmp;
		tmp->right = current;
	}
	else
	{
		current = new_node->right, new_node->right = tmp->right;
		if (new_node->right)
		new_node->right->parent = new_node;
		tmp->right = current;
		if (tmp->right)
		tmp->right->parent = tmp;
		current = new_node->left, new_node->left = tmp;
		tmp->left = current;
	}
	if (current)
		current->parent = tmp;
	new_node->parent = tmp->parent;
	if (tmp->parent && tmp->parent->right == tmp)
		tmp->parent->right = new_node;
	else if (tmp->parent)
		tmp->parent->left = new_node;
	tmp->parent = new_node;
	}
if (new_node && !new_node->parent)
*root = new_node;
return (new_node);
}
