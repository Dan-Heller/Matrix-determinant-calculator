#ifndef HEADER
#define HEADER

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int** BuildMatrix(int n);
void PrintMatrix(int** Mat, int n);
void FreeMatrix(int** Mat, int n);
int** BuildTheMinor(int** Mat, int n, int r, int c);
int FindDeterminant(int** Mat, int n);


#endif