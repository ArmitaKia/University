#include <iostream>
#include <regex>

using namespace std;

class Person
{
    protected:
    string firstName;
    string lastName;
    string id;
    double* workHours;

    public:
    Person();
    Person(string firstName,string lastName,double* workHours);
    Person(string firstName,string lastName,string id,double* workHours);
    Person(const Person& person);
    ~Person();
  
    Person& Person::operator = (const Person &person);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setId(string id);
    void setWorkHours(double workHours);
    string getFirstName();
    string getLasttName();
    string getId();
    double getWorkHours();
    double calculateSalary(double workHours);
    bool validate(string idString);

    friend ostream& operator << (ostream& strm , const Person person);
    friend istream& operator >> (istream& strm , Person& person);
};
    ostream& operator << (ostream& strm , const Person person);
    istream& operator >> (istream& strm , Person& person);
