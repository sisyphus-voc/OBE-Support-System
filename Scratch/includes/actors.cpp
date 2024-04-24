#include <iostream>
#include <vector>
#include <string>

using namespace std;


//Actors

class User
{
private:
    string userName;
    string password;
    string name;
    long long int PhoneNumber;
    

public:
    // constructor
    User(string, string){

    }

    // setters
    void setUserName(string){

    }
    void setPassword(string){

    }
    void setName(string){

    }

    // getters
    string getUserName(string){

    }
    string getPassword(string){

    }
    string getName(string){

    }
};

class AcademicOfficer : public User
{
private:
    string Officername;
public:
    // constructor
    AcademicOfficer();

    // setters

    // getters

    // Member Functions

    // Programs
    void addProgram(Program){}
    void removeProgram(Program){}
    void updateProgram(Program){}

    // Course
    void addCourse(Course){}
    void removeCourse(Course){}
    void updateCourse(Course){}

    // PLO
    void addPlo(PLO){}
    void removePlo(PLO){}
    void updatePlo(PLO){}

    // CLO
    void addClo(CLO){}
    void removeClo(CLO){}
    void updateClo(CLO){}

    void generatCourseReport(Course){}
    void generatePloReport(PLO){}
};

class Teacher : public User
{
private:
    string teacherName;
    string department;
    long long int phoneNumber;

public:
    // constructor
    Teacher();

    // setters
    void setTeacher(string){}

    // getters
    string getTeacher(){}

    // Member Functions
    void addTopicsToClo(CLO, string *){}
};


//Tasks

class PLO{
private:
    string ploCode;
    string ploDescription;
    CLO* clos;
public:
    //constructors
    PLO(string c, string d){ 
        ploCode = c;  
        ploDescription = d;  
        clos = NULL; 
    }
    
    void addCLO(CLO *clo) {
                                
    }
    
    //getters
    string getPLOcode() const { return ploCode; }
    string getPLOfullDesc() const { return ploDescription; }

    

};

class CLO{
private:
    string cloCode;
    string cloDescription;
    PLO* plos;
public:
    //constructors
    CLO(string c, string d){
        cloCode=c;
        cloDescription=d;
    }
    //setters

void setCLOnumber(string n) { cloCode = n;}
void setCLOnote(string n) { cloDescription = n;}

    //getters
    string getCLOnumber() const {return cloCode;}
    string getCLOnote() const {return cloDescription;}

    int getNumberofPLOs() const { return sizeof(plos)/sizeof(plos[0]);}

    

};

class Program{
private:
    string programCode;
    string programDesc;
    PLO* plos;
public:



};

//Course
class Course{
private:
    string courseCode;
    string courseDescription;
    Program program;
    CLO* clos;
public:
    


};