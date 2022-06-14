#ifndef PROFESSOR
#define PROFESSOR

#include <iostream>
#include "Person.h"
using namespace std;

class Professor : public Person
{
private:
    string title;

public:
    Professor();
    Professor(string firstName,string lastName,string id,double workHours,string title);
    Professor(const Professor& professor);
    friend ostream& operator << (ostream& strm , const Professor& professor);
    friend istream& operator >> (istream& strm , Professor& professor);
    Professor& operator = (const Professor &t);
    double calculateSalary();
    static bool validId(string idString);
    static bool checkTitle(string title);
    string getTitle();
    void setTitle(const string &title);
};
ostream& operator << (ostream& strm , const Professor& professor);
istream& operator >> (istream& strm , Professor& professor);
#endif