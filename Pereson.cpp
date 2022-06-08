#include "Person.h"

    Person::Person()
    {
        workHours = new double;
    }
    Person::Person(string firstName,string lastName,double* workHours)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->workHours = new double;
        *(this->workHours) = *workHours;
    }
    Person::Person(string firstName,string lastName,string id,double* workHours)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        if(validate(id))
            this->id = id;
        else
        {
            cout << "invalid id" << endl;
            exit(0);
        }
        this->workHours = new double;
        *(this->workHours) = *workHours;
    }//use to main
    Person::Person(const Person& person)
    {
        this->firstName = person.firstName;
        this->lastName = person.lastName;
        this->id = person.id;
        *(this->workHours) = *person.workHours;
    }
    Person::~Person()
    {
        delete workHours;
    }
    ostream& operator << (ostream& strm , const Person person)
    {
        strm << "person name: " << person.firstName << " " << person.lastName << "  id: " << person.id << "  work hours: " << *person.workHours; 
        return strm;
    }
    istream& operator >> (istream& strm , Person& person)
    {   
        cout << "Enter first name,last name,id and work hours of the person: " << endl;
        double workHours;
        string id;
        strm >> person.firstName >> person.lastName >> id >> workHours;
        if(Person::validate(id))
            person.id = id;
        else
        {
            cout << "invalid id" << endl;
            exit(0);
        }
        *person.workHours = workHours;
        return strm;    
    }
    Person& Person::operator = (const Person &person)
    {
        if(this != &person)
        {
            this->firstName = person.firstName;
            this->lastName = person.lastName;
            this->id = person.id;
            *(this->workHours) = *person.workHours;
        }
        return *this;
    }//doroste
    //az inja be bad ham doroste:)
    void Person::setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void Person::setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    void Person::setId(string id)
    {
        this->id = id;
    }
    void Person::setWorkHours(double workHours)
    {
        *(this->workHours) = workHours;
    }
    string Person::getFirstName()
    {
        return firstName;
    }
    string Person::getLastName()
    {
        return lastName;
    }
    string Person::getId()
    {
        return id;
    }
    double Person::getWorkHours()
    {
        return *workHours;
    }
    double Person::calculateSalary(double workHours)
    {
        return 10000*workHours;
    }
    bool Person::validate(string idString)
    {
        bool x;
        string str =  "(84|85|86|87|88|89|90|91|92|93|94|95|96|97|98|99|00)(\\D{1,3})(\\d[1237890]{5})";
        regex reg(str);
        smatch matches;
        x=regex_search(idString,matches,reg);
    }
