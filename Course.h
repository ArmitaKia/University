#ifndef COURSE
#define COURSE

#include <iostream>

using namespace std;

class Course 
{
    public:
    string name;
    int unit;
    double* mark;

    public:
    Course();
    Course(string name,int unit,double* mark);
    Course(const Course& course);
    ~Course();
    friend ostream& operator << (ostream& strm , const Course& course);
    friend istream& operator >> (istream& strm , Course course);
    void setName(string name);
    void setUnit(int unit);
    void setMark(double mark);
    string getName();
    int getUnit();
    double getMark();
    Course& operator = (const Course &t);
};
    ostream& operator << (ostream& strm , const Course& course);
    istream& operator >> (istream& strm , Course course);
#endif