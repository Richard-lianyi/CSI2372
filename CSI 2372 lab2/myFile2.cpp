//
// Created by liany on 2024-10-08.
//
#include "myFile2.h"
#include <iostream>
using namespace std;

void sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[10] = {2, 4, 88, 20, 3, 55, 87, 134, 2, 5};

    cout << "Displaying the unsorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, 10);

    cout << "Displaying the sorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
