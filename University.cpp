
#include "University.h"
    University::University()
    {
        this->professors = new Professor[numOfProfessors];
        this->students = new Student[numOfStudent];
    }
    University::University(int budget,int numOfProfessors,int numOfStudent,Professor* professors,Student* students)
    {
        this->budget = budget;
        this->numOfProfessors = numOfProfessors;
        this->numOfStudent = numOfStudent;
        this->professors = new Professor[numOfProfessors];
        for(int i=0;i<numOfProfessors;i++)
            this->professors[i] = professors[i];
        this->students = new Student[numOfStudent];
        for(int i=0;i<numOfStudent;i++)
            this->students[i] = students[i];
    }
    University::University(const University& university)
    {
        this->budget = university.budget;
        this->numOfProfessors = university.numOfProfessors;
        this->numOfStudent = university.numOfStudent;
        for(int i=0;i< this->numOfProfessors;i++)
            this->professors[i] = university.professors[i];
        for(int i=0;i< this->numOfStudent;i++)
            this->students[i] = university.students[i];
    }
    University::~University()
    {
        delete professors;
        delete students;
    }
    void University::setProfessorsAndStudents(Professor* professors,Student* student)
    {
        for(int i=0;i<numOfProfessors;i++)
            this->professors[i] = professors[i];
        for(int i=0;i<numOfStudent;i++)
            this->students[i] = students[i];
    }
    double University::averageGpa()
    {
        Student* ptStudent = students;
        double sum;
        for(int i=0;i<numOfStudent;i++)
        {
            sum += ptStudent->gpa();
            ptStudent++;
        }
        return sum/numOfStudent;////////////ye limiti ham bezaram khob mishe
    }
    double University::averageGpaOfField(string fieldOfStudy)
    {
        double sum;
        Student* ptStudent = students;
        int number = 0;
        for(int i=0;i<numOfStudent;i++)
        {
            if(ptStudent->fieldOfStudy == fieldOfStudy)
            {
                sum += *((ptStudent->course)->mark);
                number++;
            }
            ptStudent++;
        }
        return sum/number;//// ye limiti ham inja bezaram khob mishe
    }
    double University::averageMarkOfCourse(Course course)
    {
        double sum;
        Student* ptStudent = students;
        int number = 0;
        for(int i=0;i<numOfStudent;i++)
        {
            if(ptStudent->course->name == course.name)
            {
                sum += *((ptStudent->course)->mark);
                number++;
            }
            ptStudent++;
        }
        return sum/number;//// ye limiti ham inja bezaram khob mishe
    }
    bool University::isEnoughBudget()
    {
        double totalSalary;
        Professor* ptProfessor = professors;
        Student* ptStudent = students;
        for(int i=0;i<numOfProfessors;i++)
        {
            totalSalary += ptProfessor->Professor::calculateSalary();
            ptProfessor++;
        }
        for(int i=0;i<numOfStudent;i++)
        {
            totalSalary += ptStudent->Student::calculateSalary();
            ptProfessor++;
        }
        if(totalSalary<=budget)
            return true;
        return false;
        
    }
    ///functione to file rekhtan monde
    ostream& operator << (ostream& strm , University university)
    {
        university.bubbleSort(university.professors,university.numOfProfessors);
        for(int i=0;i<university.numOfProfessors;i++)
        {
            strm << i <<"." << university.professors[i].getTitle() << " " <<  university.professors[i].getFirstName() << " " << university.professors[i].getLastName()<< endl;
        }

        university.bubbleSort(university.students,university.numOfStudent);
        for(int i=0;i<university.numOfStudent;i++)
        {
            strm << i <<"." << " " <<  university.students[i].getFirstName() << " " << university.students[i].getLastName()<< " work hours: "
            << university.students[i].getWorkHours()<< endl;//dige chya benevisam zibatar she?
        }

    }
    istream& operator >> (istream& strm , University& university)
    {
        cout << "Enter budget and number of professors and number of student :" << endl;
        strm >> university.budget >> university.numOfProfessors >> university.numOfStudent;
        return strm;
    }
    void University::bubbleSort(Professor* prof, int n)
    {
        
        int i, j;
        for(i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                {
                    

                    if (calculateYear(prof[j]) > calculateYear(prof[j + 1]))
                        swap(prof[j], prof[j + 1]);
                    if(calculateYear(prof[j]) == calculateYear(prof[j + 1]))
                    { 
                       //bayad bar hasbe horof alephba sort she
                    }
                }
    }
    int University::calculateYear(Professor prof)
    {
        int year;
        string firstTwo;
        firstTwo = prof.getId().substr(0, 2);
                    if(firstTwo =="00")
                        year = 0;  
                    else
                        year = 100 - stoi(firstTwo);
        return year;
    }
    void University::swap (Professor prof1,Professor prof2)
    {
        Professor temp;
        temp = prof1;
        prof1 = prof2;
        prof2 = temp;
    }


    void University::bubbleSort(Student* studnet, int n)
    {
        
        int i, j;
        for(i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                {
                    

                    if (calculateYear(studnet[j]) > calculateYear(studnet[j + 1]))
                        swap(studnet[j], studnet[j + 1]);
                    if(calculateYear(studnet[j]) == calculateYear(studnet[j + 1]))
                    { 
                       //bayad bar hasbe horof alephba sort she
                    }
                }
    }
    int University::calculateYear(Student studnet)
    {
        int year;
        string firstTwo;
        firstTwo = studnet.getId().substr(0, 2);
                    if(firstTwo =="00")
                        year = 0;  
                    else
                        year = 100 - stoi(firstTwo);
        return year;
    }
    void University::swap (Student studnet1,Student studnet2)
    {
        Student temp;
        temp = studnet1;
        studnet1 = studnet2;
        studnet2 = temp;
    }
