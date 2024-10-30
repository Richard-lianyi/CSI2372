//
// Created by liany on 2024-10-29.
//
#include <cstdlib>
using namespace std;

class SetInt {
private:
    int* elements; // Pointer to store elements
    int size;      // Number of elements

public:
    SetInt(); // Default constructor
    SetInt(int* arr, int arrSize); // Constructor with array input
    SetInt(const SetInt& other);
    ~SetInt(); // Destructor
    void add(int value);
    void remove(int value);
    bool contains(int value) const;
    int nbElem() const;
    int* tabElem() const;
    bool containsAux(int value, int position) const;
};

