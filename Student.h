#include <iostream>
#include "Person.h"
#include "Course.h"

using namespace std;

class Student : public Person 
{
    public:
    Course* course;
    string fieldOfStudy;
    int numOfCourse;

    public:
    Student();   
    Student(string firstName,string lastName,string id,double* workHours,Course* course,string fieldOfSutdy,int numOfCourse)
    :Person(firstName,lastName,workHours){};
    Student(const Student& student):Person(student){};//inja {} hast moshkeli nadare?
    ~Student();
    void setCourse(Course* ptCourse);
    double gpa();
    double calculateSalary(double workHours);
    static bool validate(string idString);
    
    friend ostream& operator << (ostream& strm , const Student student);
    friend istream& operator >> (istream& strm , Student& student);
};
    ostream& operator << (ostream& strm , const Student student);
    istream& operator >> (istream& strm , Student& student);