#include "Course.h"
    Course::Course()
    {
        this->mark = new double;
    }
    Course::Course(string name,int unit,double* mark)
    {
        this->name = name;
        this->unit = unit;
        this->mark = new double;
        *(this->mark) = *mark;
    }
    Course::Course(const Course& course)
    {
        this->name = course.name;
        this->unit = course.unit;
        *(this->mark) = *(course.mark);
    }
    Course::~Course()
    {
        delete mark;
    }
    ostream& operator << (ostream& strm ,const Course& course)
    {
        strm << "course name: " << course.name << "  course unit: " << course.unit << "  course mark: " << *course.mark;  
        return strm;
    }
    istream& operator >> (istream& strm , Course course)
    {   
        cout << "Enter name and unit and mark of the course:" << endl;
        double mark;
        strm >> course.name >> course.unit >> mark;
        mark = *course.mark;
        return strm;    
    }
    void Course::setName(string name)
    {
        this->name = name;
    }
    void Course::setUnit(int unit)
    {
        this->unit = unit;
    }
    void Course::setMark(double mark)
    {
        *(this->mark) = mark;
    }
    string Course::getName()
    {
        return this->name;
    }
    int Course::getUnit()
    {
        return this->unit;
    }
    double Course::getMark()
    {
        return *(this->mark);
    }
