//
// Created by liany on 2024-10-29.
//
#include <iostream>
using namespace std;
class Course {
private:
    int code;          // Course number/code
    int hours;         // Number of hours for the course

public:
    Course(int c = 0, int h = 0) : code(c), hours(h) {}
    int getNum() const { return code; }
    int getHours() const { return hours; }
};


