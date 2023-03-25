#include <stdio.h>
#include <stdlib.h>
#define forn(i,n) for(i=0; i<n; i++)
#define dim 5

void scaleMatrix (int matrix[dim][dim], int scalar, int m, int n) {
    int i,j;
    forn(i,m) forn(j,n) matrix[i][j] *= scalar;
}

void printMatrix (int matrix[dim][dim], int m, int n) {
    int i,j;
    forn(i,m) {
        forn(j, n) printf("%3d ", matrix[i][j]);
        printf("\n");
    }
    printf("//////////////\n");
}

void transposeMatrix (int matrix[dim][dim], int m, int n) {
    int i,j,store;
    int result[n][m];
    forn(i,m) forn(j,n) result[j][i] = matrix[i][j];
    printf("Transposed matrix: \n");
    printMatrix(result, dim, dim);
}

void transposeSquareMatrix (int matrix[dim][dim], int m) { // revise logic
    int i,j,store;

    forn(i,m) {
        forn(j,m) {
            store = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = store;
        }
    }
}

int main()
{
    int i, j;
    int matrix[dim][dim];

    forn(i,dim) forn(j, dim) matrix[i][j] = 1 + rand() % 100; // create matrix
    // printMatrix(matrix, dim, dim);

    scaleMatrix(matrix, 2, dim, dim);
    printf("Scaled matrix: \n");
    printMatrix(matrix, dim, dim);

    transposeMatrix(matrix, dim, dim);
}
