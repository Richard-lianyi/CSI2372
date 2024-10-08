//
// Created by liany on 2024-10-08.
//
#include <iostream>
using namespace std;

int** triangleInf(int n) {
    // Allocate memory for the lower triangular matrix
    int** triangle = new int*[n];
    for (int i = 0; i < n; i++) {
        triangle[i] = new int[i + 1];
    }

    // Fill the matrix using Pascal's triangle properties
    for (int i = 0; i < n; i++) {
        triangle[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }

    return triangle;
}

int main() {
    int n = 10;
    int** triangle = triangleInf(n);

    // Print the Pascal's triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;

    return 0;
}
