#ifndef COURSE
#define COURSE

#include <iostream>

using namespace std;

class Course
{
private:
    string name;
    int unit;
    double* mark;

public:
    Course();
    Course(string name,int unit,double mark);
    Course(const Course& course);
    ~Course();
    friend ostream& operator << (ostream& strm , const Course& course);
    friend istream& operator >> (istream& strm , Course course);
    void setName(string name);
    void setUnit(int unit);
    void setMark(double mark);
    string getName() const;
    int getUnit();
    Course& operator = (const Course &t);
    double getMark() const;
};
ostream& operator << (ostream& strm , const Course& course);
istream& operator >> (istream& strm , Course course);
#endif