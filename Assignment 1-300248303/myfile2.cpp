//
// Created by liany on 2024-10-01.
//The main() function in Annex A2 implements a menu-driven program that
//allows users to calculate either the surface area of a disk or the volume
//of a cylinder based on user input. It continuously prompts the user for choices
//until they decide to exit. Upon exit, it displays the number of times each calculation
//function (surface and volume) was executed.
//
#include <iostream>
#include <cmath>    // for M_PI
#include "myfile2.h"

using namespace std;

// Function to display the menu and get user input
char menu() {
    char choice;
    cout << "What do you want to do?:" << endl;
    cout << "-Calculate the area of a disk from a radius (Press 1)" << endl;
    cout << "-Calculate the volume of a cylinder from a radius and a height (Press 2)" << endl;
    cout << "-Exit the program (Press 3)" << endl;
    cout << "Your choice: ";
    cin >> choice;
    return choice;
}

// Function to calculate the surface area of a disk
double surface(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the volume of a cylinder
double volume(double radius, double height) {
    return M_PI * radius * radius * height;
}

// Main function
int main() {
    char choice;
    int nvolume = 0; // number of times the volume function has been executed
    int nsurface = 0; // number of times the surface function has been executed
    double radius, height;

    while (1) {
        choice = menu();
        switch (choice) {
            case '1': {
                cout << endl << "Surface calculation" << endl;
                cout << "Enter the radius: ";
                cin >> radius;
                double result = surface(radius);
                nsurface++;
                cout << "The surface is: " << result << endl;
                break;
            }
            case '2': {
                cout << endl << "Volume calculation" << endl;
                cout << "Enter the radius: ";
                cin >> radius;
                cout << "Enter the height: ";
                cin >> height;
                double result = volume(radius, height);
                nvolume++;
                cout << "The volume is: " << result << endl;
                break;
            }
            case '3': {
                cout << endl << "Exit the program" << endl;
                cout << "The volume function has been executed " << nvolume << " times" << endl;
                cout << "The surface function has been executed " << nsurface << " times" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    }
}
