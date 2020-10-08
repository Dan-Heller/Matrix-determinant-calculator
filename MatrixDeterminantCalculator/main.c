#include "header.h"


void main() {

	int n, Determinant;

	printf("dan Enter the order of the matrix with one number: ");
	scanf("%d", &n);

	int** Mat = BuildMatrix(n);

	Determinant = FindDeterminant(Mat, n);

	printf("The determinant of the matrix is: %d", Determinant);

	FreeMatrix(Mat, n);

}

