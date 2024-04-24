#include <iostream>

using namespace std;

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