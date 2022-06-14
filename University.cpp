#include "University.h"
#include "Professor.h"
#include "Student.h"

University::University():budget(0),numOfStudent(0),numOfProfessors(0)
{
    this->professors = new Professor[20];
    this->students = new Student[20];
}
University::University(int budget,int numOfProfessors,int numOfStudent,Professor* professors,Student* students)
{
    this->budget = budget;
    this->numOfProfessors = numOfProfessors;
    this->numOfStudent = numOfStudent;
    this->professors = new Professor[numOfProfessors];
    for(int i=0;i<numOfProfessors;i++)
        this->professors[i] = professors[i];
    this->students = new Student[numOfStudent];
    for(int i=0;i<numOfStudent;i++)
        this->students[i] = students[i];
}
University::University(const University& university)
{
    this->budget = university.budget;
    this->numOfProfessors = university.numOfProfessors;
    this->numOfStudent = university.numOfStudent;
    students = new Student[university.numOfStudent];
    for(int i=0;i< this->numOfProfessors;i++)
        this->professors[i] = university.professors[i];
    professors = new Professor[university.numOfProfessors];
    for(int i=0;i< this->numOfStudent;i++)
        this->students[i] = university.students[i];
}
University::~University()
{
    delete [] professors;
    delete [] students;
}
void University::setProfessorsAndStudents(Professor* professors,Student* student)
{
    for(int i=0;i<numOfProfessors;i++)
        this->professors[i] = professors[i];
    for(int i=0;i<numOfStudent;i++)
        this->students[i] = students[i];
}
double University::averageGpa()const
{
    double sum =0;
    for(int i=0;i<numOfStudent;i++)
    {
        sum += students[i].gpa();
    }
    return sum/numOfStudent;
}
double University::averageGpaOfField(const string& fieldOfStudy)
{
    double sum = 0;
    Student* ptStudent = students;
    int number = 0;
    for(int i=0;i<numOfStudent;i++)
    {
        if(ptStudent->getFieldOfStudy() == fieldOfStudy)
        {
            sum += (ptStudent->getCourse())->getMark();
            number++;
        }
        ptStudent++;
    }
    return sum/number;
}
double University::averageMarkOfCourse( const Course& course)
{
    double sum =0;
    Student* ptStudent = students;
    double number = 0;
    for(int i=0;i<numOfStudent;i++)
    {
        if(ptStudent->getCourse()->getName() == course.getName())
        {
            sum += (ptStudent[i].getCourse())->getMark();
            number++;
        }
        ptStudent++;
    }
    return sum/number;
}
bool University::isEnoughBudget()
{
    double totalSalary;
    Professor* ptProfessor = professors;
    Student* ptStudent = students;
    for(int i=0;i<numOfProfessors;i++)
    {
        totalSalary += ptProfessor->Professor::calculateSalary();
        ptProfessor++;
    }
    for(int i=0;i<numOfStudent;i++)
    {
        totalSalary += ptStudent->Student::calculateSalary();
        ptProfessor++;
    }
    if(totalSalary<=budget)
        return true;
    return false;

}
ostream& operator << (ostream& strm , University& university)
{
    cout << "---- UNIVERSITY INFO ----" << endl;
    cout << "### professors information ###" << endl;
    university.bubbleSort(university.professors,university.numOfProfessors);
    cout << "Based on work experience and alphabetical sort" << endl;
    for(int i=0;i<university.numOfProfessors;i++)
    {
        strm << i+1 <<"." << university.professors[i].getTitle() << " " <<  university.professors[i].getFirstName() << " " << university.professors[i].getLastName()<< endl;
    }
    cout << "### student information ###" << endl;
    university.bubbleSort(university.numOfStudent);
    cout << "Based on study history and alphabetical sort" << endl;
    for(int i=0;i<university.numOfStudent;i++)
    {
        strm << i+1 <<"." <<  university.students[i].getFirstName() << " " << university.students[i].getLastName()<< " work hours: "
             << university.students[i].getWorkHours()<< endl;
    }
    return strm;

}
istream& operator >> (istream& strm , University& university)
{
    cout << "Enter budget and number of professors and number of student :" << endl;
    strm >> university.budget >> university.numOfProfessors >> university.numOfStudent;
    return strm;
}
void University::bubbleSort(Professor* prof, int n)
{
    int i, j;
    for(i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            if (calculateYear(prof[j]) > calculateYear(prof[j + 1]))
            {

                swap(prof[j], prof[j + 1]);

            }
            if(calculateYear(prof[j]) == calculateYear(prof[j + 1]))
            {
                if(prof[j].getFirstName()>prof[j+1].getFirstName())
                    swap(prof[j],prof[j+1]);
            }
        }
}
int University::calculateYear(Professor prof)
{
    int year =0;
    string firstTwo;
    firstTwo = prof.getId().substr(0, 2);
    if(firstTwo =="00")
        year = 0;
    else
        year = 100 - stoi(firstTwo);
    return year;
}
void University::bubbleSort(int n)
{
    Student* s = this->students;
    for(int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {


            if (calculateYear(s[j]) > calculateYear(s[j + 1]))
                swap(s[j], s[j + 1]);
            if(calculateYear(s[j]) == calculateYear(s[j + 1]))
            {
                if(s[j].getFirstName()>s[j+1].getFirstName())
                    swap(s[j],s[j+1]);
            }
        }
}
int University::calculateYear(Student studnet)
{
    int year;
    string firstTwo;
    firstTwo = studnet.getId().substr(0, 2);
    if(firstTwo =="00")
        year = 0;
    else
        year = 100 - stoi(firstTwo);
    return year;
}
void University::printCourses(Course* courses, int numOfCourses ){
    bubbleSort(courses,numOfCourses);
    for(int i=0;i<numOfCourses;i++){
        cout<<courses[i]<<endl;
    }

}
void University::bubbleSort(Course* courses, int n )
{
    for(int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if(averageMarkOfCourse(courses[j]) > averageMarkOfCourse(courses[j+1]))
                swap(courses[j],courses[j+1]);
        }


}