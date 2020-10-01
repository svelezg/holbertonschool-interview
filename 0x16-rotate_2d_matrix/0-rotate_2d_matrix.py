#!/usr/bin/python3
""" Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """
    :param matrix: matrix to rotate
    :return: Do not return anything. The matrix must be edited in-place.
    """
    matrix.reverse()
    matrix_tmp = [row.copy() for row in matrix]

    for i, row in enumerate(matrix_tmp):
        for j, n in enumerate(row):
            matrix[j][i] = matrix_tmp[i][j]
