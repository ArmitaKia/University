#include "Professor.h"
#include "Course.h"
Professor::Professor()
{}
Professor::Professor(string firstName,string lastName,string id,double* workHours,string title):Person::Person(firstName,lastName,workHours)
{
    if(validId(id))
        this->id = id;
    else
    {
        cout << "invalid id" << endl;
        exit(0);
    }
    if(checkTitle(title))
        this->title = title;
    else
    {
        cout << "invalid title" << endl;
        exit(0);
    }

}
Professor::Professor(const Professor& professor):Person(professor)
{
    this->title = professor.title;
}
ostream& operator << (ostream& strm , const Professor& professor)
{
    cout << "---- Professor information ----" << endl;
    strm << "Professor:" << professor.title << " " << professor.firstName << " " << professor.lastName
         << "  id: " << professor.id << "  work hours: " << *professor.workHours;
    return strm;
}
istream& operator >> (istream& strm , Professor& professor)
{
    cout << "Enter first name,last name,id and work hours of the perofessor: " << endl;
    double workHours;
    string id;
    strm >> professor.firstName >> professor.lastName >> id >> workHours;
    if(Professor::validId(id))
        professor.id = id;
    else
    {
        cout << "invalid id" << endl;
        exit(0);
    }
    *professor.workHours = workHours;
    cout << "Enter title (Instructor-Assistant Professor-Associate Professor-Professor)" << endl;
    string title;
    strm >> title;
    if(Professor::checkTitle(title))
        professor.title = title;
    else
    {
        cout << "invalid title" << endl;
        exit(0);
    }

    return strm;
}
double Professor::calculateSalary()
{
    double baseSalary = 50000;
    double profLevelSalary = 0;

    string s1,s2,s3,s4;
    s1 ="Instructor" ;
    s2 = "Assistant Professor";
    s3 = "Associate Professor" ;
    s4 = "Professor";
    if(title == s1)
        profLevelSalary = 10000;
    if(title == s2)
        profLevelSalary = 20000;
    if(title == s3)
        profLevelSalary = 30000;
    if(title == s4)
        profLevelSalary = 40000;

    double levelBaseSalary = 0;
    string firstTwo = this->id.substr(0, 2);
    int year;
    if(firstTwo =="00")
        year = 0;
    else
        year = 100 - stoi(firstTwo);
    double extraSalary = year*2000;
    return baseSalary+levelBaseSalary+extraSalary+profLevelSalary;
}
bool Professor::validId(string idString)
{
    bool x;
    regex reg(R"(([84-99]{2}|[00]{2})(#)(\D{0,2})([1237890]{5})$)");
    smatch matches;
    x=regex_search(idString,matches,reg);
    cout << x;
    return x;
}
bool Professor::checkTitle(string title)
{
    string s1,s2,s3,s4;
    s1 ="Instructor" ;
    s2 = "Assistant Professor";
    s3 = "Associate Professor" ;
    s4 = "Professor";
    if(title == s1 || title == s2  || title == s3|| title == s4 )
        return true;
    return false;
}
string Professor::getTitle()
{
    return title;
}
Professor& Professor::Professor::operator = (const Professor &t)
{
    if(this != &t)

    {
        firstName = t.firstName;
        lastName = t.lastName;
        id = t.id;
        *workHours = *(t.workHours);
        title = t.title;
    }
    return *this;
}
