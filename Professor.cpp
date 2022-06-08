#include "Professor.h"
    Professor::Professor()
    {}
    Professor::Professor(string firstName,string lastName,string id,double* workHours,string title):Person(firstName,lastName,workHours)
    {
         if(validate(id))
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
    ostream& operator << (ostream& strm , const Professor professor)
    {
        strm << "Professor:" << professor.title << " " << professor.firstName << " " << professor.lastName 
        << "  id: " << professor.id << "  work hours: " << *professor.workHours;
        return strm;
    }
    istream& operator >> (istream& strm , Professor& professor)
    {   
        cout << "Enter first name,last name,id and work hours of the student: " << endl;
        double workHours;
        string id;
        strm >> professor.firstName >> professor.lastName >> id >> workHours;
        if(Professor::validate(id))
            professor.id = id;
        else
        {
            cout << "invalid id" << endl;
            exit(0);
        }
        *professor.workHours = workHours;
        cout << "Enter title :" << endl;
        string title;
        strm >> title;
        if(checkTitle(title))
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
    bool Professor::validate(string idString)
    {
        bool x;
        string str =  "(84|85|86|87|88|89|90|91|92|93|94|95|96|97|98|99|00)(#)(\\D{0,2})(\\d[1237890]{5})";
        regex reg(str);
        smatch matches;
        x=regex_search(idString,matches,reg);
    }
    bool checkTitle(string title)
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
