#include <stdlib.h>
#include <stdio.h>


/**
 * print_grid - prints grid.
 *
 * @grid: grid to print.
 */

static void print_grid(int grid[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]);
}
printf("\n");
}
}

/**
 * is_stable - checks if sandpile is stable.
 *
 * @grid: grid to check.
 * Return: 1 if stable 0 if not.
 */
int is_stable(int grid[3][3])
{
int i, j, k = 0;
for (i = 0; i < 3; i++)
{
	for (j = 0; j < 3; j++)
	{
		if (grid[i][j] > 3)
			k += 1;
	}
}
if (k == 0)
	return (1);
else
	return (0);
}

/**
 * sandpiles_simple_sum - sums sandpiles.
 *
 * @grid1: grid1.
 * @grid2: grid2.
 * Return: The simple sandpile sum (without tupling).
 */

void sandpiles_simple_sum(int grid1[3][3], int grid2[3][3])
{
int i, j, c = 0;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
c = grid1[i][j] + grid2[i][j];
grid2[i][j] = c;
grid1[i][j] = c;
}
}
printf("=\n");
print_grid(grid1);
}

/**
 * sandpiles_sum - inserts a value in a binary heap.
 *
 * @grid1: root of a tree.
 * @grid2: value to insert.
 * Return: The new node or null.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	sandpiles_simple_sum(grid1, grid2);

while (is_stable(grid1) != 1)
{
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid1[i][j] > 3)
	grid1[i][j] -= 4;
if ((i > 0) && (grid2[i - 1][j] > 3))
	grid1[i][j] += 1;
if ((i < 2) && (grid2[i + 1][j] > 3))
	grid1[i][j] += 1;
if ((j > 0) && (grid2[i][j - 1] > 3))
	grid1[i][j] += 1;
if ((j < 2) && (grid2[i][j + 1] > 3))
	grid1[i][j] += 1;
}
}
if (is_stable(grid1))
	break;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
grid2[i][j] = grid1[i][j];
}
}
printf("=\n");
print_grid(grid1);
}
}
