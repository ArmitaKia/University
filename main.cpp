#include <iostream>
#include "Person.h"
#include "Student.h"
#include "process.h"
#include "University.h"

using namespace std;

int main()
{
    Course* ptCourses = new Course[7];
    for(int i=0;i<7;i++)
        cin >> ptCourses[i];
    //There are 7 courses 

    Student* ptStudent = new Student[12];
    for(int i=0;i<12;i++)
        cin >> ptStudent[i];
    //There are 12 students

    Professor* ptProfessors = new Professor[3];
    for(int i=0;i<3;i++)
        cin >> ptProfessors[i];
    //There are 3 Professors

    cout << "The station of Courses" << endl;
    for(int i=0;i<7;i++)
        cout << ptCourses[i];

    cout << "The station of Students" << endl;
    for(int i=0;i<12;i++)
        cout << ptStudent[i];

    cout << "The station of Professors" << endl;
    for(int i=0;i<3;i++)
        cout << ptProfessors;
   
    University university(6000000,3,12,ptProfessors,ptStudent);
    cout << "The station of University" << endl;
    cout << university;

    cout << "moadel tamame daneshjoha: " << university.averageGpa() << endl;
    cout << "moadel tamame daneshjoha dar har reshte" << endl;
    // for(int i=0;i<12;i++)
    //     if(1==1)//che jori beyad tekrari nagire
    //         cout << i << ". "<<  ptStudent[i].fieldOfStudy << university.averageGpaOfFiled(ptStudent[i].fieldOfStudy) << endl;
    // cout << "moadel kaneshjoha dar har dars "<< endl;
    // for(int i=0;i<7;i++)
    //     cout << i << ". " << ptCourses[i].getName() << university.averageMarkOfCourse(ptCourses[i].getName()) << endl;
    // cout << "chap doros be tartib miyangin daneshjoyan" << endl;
    // university.printCourse();
    





    delete ptCourses;
    delete ptStudent;
    delete ptProfessors;

    return 0;
}