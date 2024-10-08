//
// Created by liany on 2024-10-08.
//
#include "MyFile4.h"
#include <iostream>
#include <cstring>
using namespace std;

void display(char* tab[], int const& nbre) {
    for (int i = 0; i < nbre; i++) {
        cout << "The string " << i << " is: " << tab[i] << endl;
    }
}

void replace(char* tab[], int const& nbre, int index, const char* newStr, int size) {
    if (index < 0 || index >= nbre) {
        cout << "Invalid index!" << endl;
        return;
    }
    strncpy(tab[index], newStr, size);
}

void sort(char* tab[], int const& nbre) {
    for (int i = 1; i < nbre; i++) {
        char* key = tab[i];
        int j = i - 1;

        while (j >= 0 && strcmp(tab[j], key) > 0) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

int main() {
    const int nbre = 5;
    char* tab[nbre];

    cout << "Enter the 5 character strings ending with a tab and a line return:" << endl;

    for (int i = 0; i < nbre; i++) {
        tab[i] = new char[21]; // Each string can have a maximum of 20 characters
        cin.getline(tab[i], 21);
    }

    // Display the strings immediately after input
    display(tab, nbre);

    int choice;
    do {
        cout << "\nMenu\n1) Strings display.\n2) Replacement of a string by another one\n3) Sorting strings\n4) Exit the program\nYour choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                display(tab, nbre);
                break;
            case 2: {
                int index;
                char newStr[21];
                cout << "Enter the string number to modify: ";
                cin >> index;
                cin.ignore();
                cout << "Enter the new string: ";
                cin.getline(newStr, 21);
                replace(tab, nbre, index, newStr, 21);
                break;
            }
            case 3:
                sort(tab, nbre);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    // Free allocated memory
    for (int i = 0; i < nbre; i++) {
        delete[] tab[i];
    }

    return 0;
}
