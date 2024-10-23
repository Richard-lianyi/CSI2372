/*Ex2 - a3 CSI2372A*/

#include <iostream>
using namespace std;

const int capacity = 20;  // Size for the student name string

// Definition of the Evaluation struct
struct Evaluation {
	char student[capacity];  // Student name
	int grade;               // Grade of the student
	Evaluation* next;        // Pointer to the next node in the list
};

// Function declarations
Evaluation* add(Evaluation*, int&);
Evaluation* remove(Evaluation*, int&);
void display(Evaluation*);
double average(Evaluation*, const int&);

