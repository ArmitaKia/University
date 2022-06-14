#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "University.h"

using namespace std;

int main()
{
    Course** ppCourse = new Course* [12];
    for(int i=0;i<12;i++)
        ppCourse[i] = new Course[3];


    Course course1("zaban",3, 12);
    Course course2("arabi",2,20);
    Course course3("riazi1",2,18);
    Course course4("fizik",3,19);
    Course course5("riazi2",3, 17);
    Course course6("difransial",3,14);
    Course course7("goasaste",4,14);

    Course* ptCourse = new Course[7];
    ptCourse[0] = course1;
    ptCourse[1] = course2;
    ptCourse[2] = course3;
    ptCourse[3] = course4;
    ptCourse[4] = course5;
    ptCourse[5] = course6;
    ptCourse[6] = course7;



    ppCourse[0][0] = course1; ppCourse[0][1] = course4; ppCourse[0][2] = course7;
    ppCourse[1][0] = course3; ppCourse[1][1] = course4; ppCourse[1][2] = course5;
    ppCourse[2][0] = course1; ppCourse[2][1] = course4; ppCourse[2][2] = course5;
    ppCourse[3][0] = course4; ppCourse[3][1] = course2; ppCourse[3][2] = course7;
    ppCourse[4][0] = course1; ppCourse[4][1] = course2; ppCourse[4][2] = course3;
    ppCourse[5][0] = course7; ppCourse[5][1] = course4; ppCourse[5][2] = course3;
    ppCourse[6][0] = course7; ppCourse[6][1] = course4; ppCourse[6][2] = course2;
    ppCourse[7][0] = course2; ppCourse[7][1] = course5; ppCourse[7][2] = course6;
    ppCourse[8][0] = course5; ppCourse[8][1] = course6; ppCourse[8][2] = course7;
    ppCourse[9][0] = course1; ppCourse[9][1] = course4; ppCourse[9][2] = course7;
    ppCourse[10][0] = course5; ppCourse[10][1] = course3; ppCourse[10][2] = course6;
    ppCourse[11][0] = course1; ppCourse[11][1] = course4; ppCourse[11][2] = course3;

    Student* pStudent = new Student[12];
    Student  student0("Armita","Bakhtiarkia","99*12312",5,ppCourse[0],"computer",3);
    Student  student1("Ali","Alavi","99*99999",5,ppCourse[1],"computer",3);
    Student  student2("Hana","Akbari","96*19312",8,ppCourse[2],"math",3);
    Student  student3("Sara","Shabani","00*12812",10,ppCourse[3],"computer",3);
    Student  student4("Reza","Ramezani","99*99999",5,ppCourse[4],"math",3);
    Student  student5("Kamran","Kamali","99*12322",5,ppCourse[5],"computer",3);
    Student  student6("Tina","kia","97*18312",3,ppCourse[6],"computer",3);
    Student  student7("Hamid","Hamidi","98*12888",5,ppCourse[7],"computer",3);
    Student  student8("Asad","Maleki","00*88312",2,ppCourse[8],"math",3);
    Student  student9("Taha","Sabori","99*98981",8,ppCourse[9],"computer",3);
    Student  student10("Mehrnaz","Habibi","99*19192",6,ppCourse[10],"math",3);
    Student  student11("Alireza","Shams","99*39811",5,ppCourse[11],"computer",3);
    cin >> student11;

    pStudent[0] = student0;
    pStudent[1] = student1;
    pStudent[2] = student2;
    pStudent[3] = student3;
    pStudent[4] = student4;
    pStudent[5] = student5;
    pStudent[6] = student6;
    pStudent[7] = student7;
    pStudent[8] = student8;
    pStudent[9] = student9;
    pStudent[10] = student10;
    pStudent[11] = student11;

    Professor* pProfessor = new Professor[3];
    Professor professor0("Fateme","Alamdari","91#11112",9,"Instructor");
    Professor professor1("Sajad","Mortazavi","95#33333",8,"Assistant Professor");
    Professor professor2("Reza","Shahedi","87#99912",11,"Professor");
    cin >> professor2;

    pProfessor[0] = professor0;
    pProfessor[1] = professor1;
    pProfessor[2] = professor2;


    University university(1000000,3,12,pProfessor,pStudent);

    cout << university;
    cout << "is enough budget of the university: ";
    if(university.isEnoughBudget()==0)
        cout << "yes" << endl;
    else if(university.isEnoughBudget()==1)
        cout << "no" << endl;
    cout << "university average gpa: " << university.averageGpa() << endl;
    cout << "university average gpa of computer filed: " << university.averageGpaOfField("computer") << endl;
    cout << "university average mark of course:(fizik) " << university.averageMarkOfCourse(ppCourse[2][1]) << endl;


    for(int i=0;i<12;i++)
        delete [] ppCourse[i];
    delete [] ptCourse;
    delete [] ppCourse;
    delete [] pStudent;
    delete [] pProfessor;


    return 0;
}