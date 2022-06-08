#include "Student.h"



    Student::Student()
    {
        course = new Course[numOfCourse];
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
    Student::Student(string firstName,string lastName,string id,double* workHours,Course* course,string fieldOfSutdy,int numOfCourse)
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
        Course* ptCourse = this->course;
        for(int i=0;i<numOfCourse;i++)
        {
            *ptCourse = *course;
            ptCourse++;
            course++;
        }
    }

    Student::Student(const Student& student):Person(student)//in doroste aya?????????????////
    {
        this->numOfCourse = student.numOfCourse;
        this->fieldOfStudy = student.fieldOfStudy;
        *(this->course) = *student.course;
    }
    Student::~Student()
    {
        delete course;
    }
    ostream& operator << (ostream& strm , const Student student)
    {
        strm << "person name: " << student.firstName << " " << student.lastName << "  id: " << student.id << "  work hours: " << *student.workHours;
        strm << endl;
        strm << "field of study: " << student.fieldOfStudy << "  number of courses: " << endl;
        Course* ptCourse = student.course;
        for(int i=0;i<student.numOfCourse;i++)
        {
            strm << "course name: " << ptCourse->name << "  course unit: " << ptCourse->unit << "  course mark: " << *ptCourse->mark;
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
            strm >> ptCourse->name >> ptCourse->unit >> mark;
            mark = *ptCourse->mark;
            ptCourse++;
        }
        return strm;    
    }
    double Student::gpa()
    {
        double sum;
        Course* ptCourse = course;
        for(int i=0;i<numOfCourse;i++)
        {
            sum += ptCourse->getMark() * ptCourse->getUnit();
            ptCourse++;
        }
        return sum/numOfCourse;
    }
    double Student::calculateSalary(double workHours)
    {
        if(gpa()>=17)
            return (20000*workHours+(20000*workHours)/10);
        return 20000*workHours;
    }
    bool Student::validate(string idString)
    {
        bool x;
        string str =  "((84|85|86|87|88|89|90|91|92|93|94|95|96|97|98|99|00)(\\*)(\\D{0,2})(\\d[1237890]{5})";
        regex reg(str);
        smatch matches;
        x=regex_search(idString,matches,reg);
    }

