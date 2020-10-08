#include "header.h"

int FindDeterminant(int** Mat, int n) {
	int Determinant = 0, sign = 1, i;

	if (n == 1) {
		return Mat[0][0];
	}
	else if (n == 2) {
		return ((Mat[0][0]) * (Mat[1][1])) - ((Mat[1][0]) * (Mat[0][1])); // if the matrix is 2x2.
	}

	else {
		for (i = 0; i < n; i++) {

			int** tempMinor = BuildTheMinor(Mat, n, 0, i);
			Determinant += (sign * Mat[0][i]) * FindDeterminant(tempMinor, n - 1);
			sign = sign * -1;
			FreeMatrix(tempMinor, n - 1);
		}
		return Determinant;
	}
}

int** BuildTheMinor(int** Mat, int n, int r, int c) {
	int i, j, num, mi = 0, mj = 0;
	int** minor = (int**)malloc(sizeof(int*) * (n - 1));
	assert(minor);
	for (i = 0; i < n; i++) {

		if (i != r) {
			minor[mi] = (int*)malloc(sizeof(int) * (n - 1));
			assert(minor[mi]);

			for (j = 0; j < n; j++) {
				if (j != c) {
					minor[mi][mj] = Mat[i][j];
					mj++;
				}
			}
			mi++;
			mj = 0;
		}
	}
	return minor;
}

int** BuildMatrix(int n) {
	int i, j, num;
	int** matrix = (int**)malloc(sizeof(int*) * (n)); //open 2d pointers matrix
	assert(matrix);
	for (i = 0; i < n; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * n);
		assert(matrix[i]);
		printf("Enter row %d: \n", i + 1);

		for (j = 0; j < n; j++) {
			scanf("%d", &num);
			matrix[i][j] = num;
		}
	}
	return matrix;
}

void PrintMatrix(int** Mat, int n) {
	int j, i;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", Mat[i][j]);
		}
		printf("\n");
	}
}

void FreeMatrix(int** Mat, int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		free(Mat[i]);
	}
	free(Mat);
}