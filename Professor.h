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
    Professor(string firstName,string lastName,string id,double* workHours,string title):Person(firstName,lastName,workHours){};
    Professor(const Professor& professor):Person(professor){};
    friend ostream& operator << (ostream& strm , const Professor professor);
    friend istream& operator >> (istream& strm , Professor& professor);
    double calculateSalary();
    static bool validate(string idString);
    bool checkTitle(string title);
    string getTitle();
};
    ostream& operator << (ostream& strm , const Professor professor);
    istream& operator >> (istream& strm , Professor& professor);
#endif