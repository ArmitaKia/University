#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "University.h"

using namespace std;

int main()
{
    int numberOfStudents = 1;
    int numberOfProfessors = 1;

    Student* ptStudent = new Student[numberOfStudents];

    for(int i=0;i<numberOfStudents;i++)
    {
        cin >> ptStudent[i];
    }
    cout << endl;

    Professor* ptProfessor = new Professor[numberOfProfessors];
    for(int i=0;i<numberOfProfessors;i++)
        cin >> ptProfessor[i];
    cout << endl;


    int defualtMark = 0;
    Course* ptCourses = new Course[1];
    ptCourses->setName("zaban");
    ptCourses->setUnit(3);
    ptCourses->setMark(0.0);

    University university(1000000,numberOfProfessors,numberOfStudents,ptProfessor,ptStudent);

    cout << university;
    cout << "is enough budget of the university: ";
    if(university.isEnoughBudget()==0)
        cout << "yes" << endl;
    else if(university.isEnoughBudget()==1)
        cout << "no" << endl;
    cout << "university average gpa: " << university.averageGpa() << endl;
    cout << "university average gpa of filed: " << university.averageGpaOfField("computer") << endl;
    cout << "university average mark of course: " << university.averageMarkOfCourse(ptCourses[0]) << endl;


    delete [] ptStudent;
    delete [] ptProfessor;
    delete [] ptCourses;
    return 0;
}