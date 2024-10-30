//
// Created by liany on 2024-10-29.
//

#include "myFile1a.h"

class Student {
private:
    int ID;
    int maxCourses;
    int numCourses;
    Course** List_course;
    int* List_grades;

public:
    Student(int id, int maxCourses) : ID(id), maxCourses(maxCourses), numCourses(0) {
        List_course = new Course*[maxCourses];
        List_grades = new int[maxCourses];
    }

    ~Student() {
        delete[] List_course;
        delete[] List_grades;
    }

    void addCourse(Course* course, int grade) {
        if (numCourses < maxCourses) {
            List_course[numCourses] = course;
            List_grades[numCourses] = grade;
            numCourses++;
        }
    }

    double average() const {
        int total = 0;
        for (int i = 0; i < numCourses; i++) {
            total += List_grades[i];
        }
        return (numCourses > 0) ? static_cast<double>(total) / numCourses : 0.0;
    }

    int totalHours() const {
        int totalHours = 0;
        for (int i = 0; i < numCourses; i++) {
            totalHours += List_course[i]->getHours();
        }
        return totalHours;
    }
};
