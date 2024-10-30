//
// Created by liany on 2024-10-29.
//
#include <iostream>
#include "myFile2.h"
using namespace std;

// Default constructor
SetInt::SetInt() : elements(nullptr), size(0) {}

int main() {
    SetInt a; 	// object creation
    int* tab;

    while (a.nbElem() < 5)
    {
        cout << "add an int element" << endl;
        int elem;
        cin >> elem;
        a.add(elem);

    }
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "remove 10 " << endl;
    a.remove(10);
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "a contains :" << a.nbElem() << " elements " << endl;
    tab = a.tabElem();
    cout << "The elements of a are :" << endl;
    for (int i =0; i<a.nbElem(); i++)
        cout << tab[i] << endl;

    return 0;
}


// Constructor with array input
SetInt::SetInt(int* arr, int arrSize) : elements(nullptr), size(0) {
    for (int i = 0; i < arrSize; ++i) {
        add(arr[i]);
    }
}

// Copy constructor
SetInt::SetInt(const SetInt& other) : elements(nullptr), size(other.size) {
    if (size > 0) {
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
}

// Destructor
SetInt::~SetInt() {
    delete[] elements; // Free dynamically allocated memory
}

// Add an integer to the set
void SetInt::add(int value) {
    // Check if the value already exists in the set
    if (!contains(value)) {
        // Create a new array with one additional element
        int* newElements = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        newElements[size] = value; // Add the new value
        delete[] elements; // Delete old array
        elements = newElements; // Point to the new array
        size++; // Increase the size
    }
}

// Remove an integer from the set
void SetInt::remove(int value) {
    if (contains(value)) {
        // Create a new array with one less element
        int* newElements = new int[size - 1];
        int j = 0;
        for (int i = 0; i < size; ++i) {
            if (elements[i] != value) {
                newElements[j++] = elements[i]; // Copy the element if it's not the one to be removed
            }
        }
        delete[] elements; // Delete old array
        elements = newElements; // Point to the new array
        size--; // Decrease the size
    }
}

// Check if an integer is in the set
bool SetInt::contains(int value) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == value) {
            return true;
        }
    }
    return false;
}

// Return the number of elements in the set
int SetInt::nbElem() const {
    return size;
}

// Return an array of the elements
int* SetInt::tabElem() const {
    if (size == 0) {
        return nullptr; // Return NULL if the set is empty
    }
    int* copy = new int[size];
    for (int i = 0; i < size; ++i) {
        copy[i] = elements[i];
    }
    return copy; // Return a copy of the elements
}

// Check membership at a specific position
bool SetInt::containsAux(int value, int position) const {
    if (position < 0 || position >= size) {
        return false; // Out of bounds
    }
    return elements[position] == value; // Check if the value matches
}