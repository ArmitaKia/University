#ifndef STUDENT
#define STUDENT

#include <iostream>
#include "Person.h"
#include "Course.h"

using namespace std;

class Student : public Person
{
private:
    Course* course;
    string fieldOfStudy;
    int numOfCourse;

public:
    Student();
    Student(string firstName,string lastName,string id,double* workHours,Course* course,string fieldOfStudy,int numOfCourse);
    Student(const Student& student);
    ~Student();
    void setCourse(Course* ptCourse);
    double gpa();
    double calculateSalary();
    static bool validate(string idString);
    Student& operator = (const Student &t);

    friend ostream& operator << (ostream& strm , Student& student);
    friend istream& operator >> (istream& strm , Student& student);

    void setFieldOfStudy(const string &fieldOfStudy);
    void setNumOfCourse(int numOfCourse);
    Course *getCourse() const;
    const string &getFieldOfStudy() const;
    int getNumOfCourse() const;
};
ostream& operator << (ostream& strm , Student& student);
istream& operator >> (istream& strm , Student& student);
#endif