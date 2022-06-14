#include "Student.h"

Student::Student()
{
    course = new Course[20];
}

int Student::getNumOfCourse() const {
    return numOfCourse;
}

void Student::setCourse(Course* ptCourse)
{
    for(int i=0;i<numOfCourse;i++)
    {
        *ptCourse = *course;
        ptCourse++;
        course++;
    }
}
Student::Student(string firstName,string lastName,string id,double workHours,Course* course,string fieldOfStudy,int numOfCourse)
        :Person(firstName,lastName,workHours)
{
    if(validate(id))
        this->id = id;
    else
    {
        cout << "invalid id" << endl;
        exit(0);
    }
    this->numOfCourse = numOfCourse;
    this->fieldOfStudy = fieldOfStudy;
    this->course = new Course[numOfCourse];
    for(int i=0;i<numOfCourse;i++)
    {
        this->course[i] = course[i];
    }
}

Student::Student(const Student& student):Person(student)
{
    this->numOfCourse = student.numOfCourse;
    this->fieldOfStudy = student.fieldOfStudy;
    this->course = new Course[student.numOfCourse];
    *(this->course) = *student.course;
}
Student::~Student()
{
    delete [] course;
}
void Student::setFieldOfStudy(const string &fieldOfStudy) {
    Student::fieldOfStudy = fieldOfStudy;
}

void Student::setNumOfCourse(int numOfCourse) {
    Student::numOfCourse = numOfCourse;
}

Course *Student::getCourse() const {
    return course;
}

const string &Student::getFieldOfStudy() const {
    return fieldOfStudy;
}
ostream& operator << (ostream& strm , Student& student)
{
    cout << "---- Student informaion ----" << endl;
    strm << "Student name: " << student.firstName << " " << student.lastName << "  id: " << student.id << "  work hours: " << *student.workHours;
    strm << endl;
    strm << "field of study: " << student.fieldOfStudy << "  number of courses: " << student.numOfCourse<< endl;
    Course* ptCourse = student.course;
    double w;
    cout << "-- Student Courses --" << endl;
    for(int i=0;i<student.numOfCourse;i++)
    {
        strm << i+1 << "." <<  "course name: " << ptCourse->getName() << "  course unit: " << ptCourse->getUnit()<< "  course mark: " << ptCourse->getMark();

        ptCourse++;
    }
    return strm;
}
istream& operator >> (istream& strm , Student& student)
{
    cout << "Enter first name,last name,id and work hours of the student: " << endl;
    double workHours;
    string id;
    strm >> student.firstName >> student.lastName >> id >> workHours;
    if(Student::validate(id))
        student.id = id;
    else
    {
        cout << "invalid id" << endl;
        exit(0);
    }
    *student.workHours = workHours;
    cout << "Enter field of study and number of courses:" << endl;
    strm >> student.fieldOfStudy >> student.numOfCourse;
    Course* ptCourse = student.course;
    for(int i=0;i<student.numOfCourse;i++)
    {
        cout << "Enter name and unit and mark of the course:" << endl;
        double mark;
        string sName;
        int iUnit;
        strm >> sName>> iUnit >> mark;
        ptCourse[i].setName(sName);
        ptCourse[i].setUnit(iUnit);
        ptCourse[i].setMark(mark);
    }
    return strm;
}
double Student::gpa()
{
    double sum =0;
    Course* ptCourse = course;
    int x =0;
    for(int i=0;i<numOfCourse;i++)
    {
        sum += ptCourse->getMark() * ptCourse->getUnit();
        x += ptCourse->getUnit();
        ptCourse++;
    }
    return sum/x;
}
double Student::calculateSalary()
{
    double workHours = *this->workHours;
    if(gpa()>=17)
        return (20000*workHours+(20000*workHours)/10);
    return 20000*workHours;
}
bool Student::validate(string idString)
{
    bool x;
    regex reg(R"((8[4-9]|9[0-9]|00)(\\*)(\D{0,2})([1237890]{5})$)");
    smatch matches;
    x=regex_search(idString,matches,reg);
    return x;
}
Student& Student::Student::operator = (const Student &t)
{
    if(this != &t)
    {
        firstName = t.firstName;
        lastName = t.lastName;
        id = t.id;
        *workHours = *(t.workHours);
        fieldOfStudy = t.fieldOfStudy;
        numOfCourse = t.numOfCourse;
        for(int i=0;i<t.numOfCourse;i++)
            course[i] = t.course[i];
    }
    return *this;
}

