#ifndef UNIVERSITY
#define UNIVERSITY
#include <iostream>

#include "Professor.h"
#include "Student.h"
#include "Course.h"


using namespace std;

class University
{
public:
    int budget;
    int numOfProfessors;
    int numOfStudent;
    Professor* professors;
    Student* students;

public:
    University();
    University(int budget,int numOfProfessors,int numOfStudent,Professor* professors,Student* students);
    University(const University& university);
    ~University();
    void setProfessorsAndStudents(Professor* professors,Student* student);
    double averageGpa() const;
    double averageGpaOfField(const string& fieldOfStudy);
    double averageMarkOfCourse(const Course& course);
    bool isEnoughBudget();
    friend ostream& operator << (ostream& strm , University& university);
    friend istream& operator >> (istream& strm , University& university);
    void bubbleSort(Professor* prof, int n);
    int calculateYear(Professor prof);
    void bubbleSort( int n);
    static int calculateYear(Student studnet);
    void printCourses(Course* courses, int numOfCourses );
    void bubbleSort(Course* courses, int numOfCourses );

};
ostream& operator << (ostream& strm , University& university);
istream& operator >> (istream& strm , University& university);
#endif