

#include <iostream>

#include "Professor.h"
#include "Student.h"


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
    double averageGpa();
    double averageGpaOfField(string fieldOfStudy);
    double averageMarkOfCourse(Course course);
    bool isEnoughBudget();
    friend ostream& operator << (ostream& strm , University university);
    friend istream& operator >> (istream& strm , University& university);
    void bubbleSort(Professor* prof, int n);
    int calculateYear(Professor prof);
    void swap (Professor prof1,Professor prof2);
    void bubbleSort(Student* studnet, int n);
    int calculateYear(Student studnet);
    void swap (Student studnet1,Student studnet2);
    void bubbleSort(Professor* prof, int n);
    int calculateYear(Professor prof);
    void swap (Professor prof1,Professor prof2);
    void bubbleSort(Student* studnet, int n);
    int calculateYear(Student studnet);
    void swap (Student studnet1,Student studnet2);
};
    ostream& operator << (ostream& strm , University university);
    istream& operator >> (istream& strm , University& university);