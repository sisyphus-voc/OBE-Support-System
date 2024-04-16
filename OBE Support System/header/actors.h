#include <iostream>
#include <vector>
#include "tasks.h"

using namespace std;

class User
{
private:
    string userName;
    string password;
    string name;

public:
    // constructor
    User(string, string, string);

    // setters
    void setUserName(string);
    void setPassword(string);
    void setName(string);

    // getters
    string getUserName(string);
    string getPassword(string);
    string getName(string);
};

class AcademicOfficer : public User
{
private:
public:
    // constructor
    AcademicOfficer();

    // setters

    // getters

    // Member Functions

    // Programs
    void addProgram(Program);
    void removeProgram(Program);
    void updateProgram(Program);

    // Course
    void addCourse(Course);
    void removeCourse(Course);
    void updateCourse(Course);

    // PLO
    void addPlo(PLO);
    void removePlo(PLO);
    void updatePlo(PLO);

    // CLO
    void addClo(CLO);
    void removeClo(CLO);
    void updateClo(CLO);

    void generatCourseReport(Course);
    void generatePloReport(PLO);
};

class Teacher : public User
{
private:
    string Department;

public:
    // constructor
    Teacher(string);

    // setters
    void setTeacher(string);

    // getters
    string getTeacher();

    // Member Functions
    void addTopicsToClo(CLO, string *);
};