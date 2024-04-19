#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include "header/menus.h"

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    // constructors
    User()
    {
        username[0] = '\0';
        password[0] = '\0';
    }
    User(string newName, string newPassword)
    {
        username = newName;
        password = newPassword;
    }
    User(const User &newUser)
    {
        username = newUser.username;
        password = newUser.password;
    }
    // setters
    void setUsername(string newName)
    {
        username = newName;
    }
    void setPassword(string newPassword)
    {
        password = newPassword;
    }
    // getters
    string getUsername()
    {
        return username;
    }
    string getPassword()
    {
        return password;
    }

    bool operator==(const User &newUser)
    {
        if (username == newUser.username && password == newUser.password)
        {
            return true;
        }
        else
            return false;
    }
    bool operator!=(const User &newUser)
    {
        if (username != newUser.username && password != newUser.password)
        {
            return true;
        }
        else
            return false;
    }
    // Print Function
};
class Teacher : public User
{
private:
    string teacherName;
    string department;
    long long int phoneNumber;
    int noOfCourses;
    vector<Course *> courses;

public:
    // Constructors
    Teacher()
    {
        teacherName[0] = '\0';
        department[0] = '\0';
        phoneNumber = 0;
        courses[0] = NULL;
        noOfCourses = courses.size();
    }
    Teacher(string newName, string newPassword, string newTeacherName, string newDepartment,
            long long int newPhoneNumber, int noOfCourses, vector<Course *> newCourse) : User(newName, newPassword)
    {
        teacherName = newTeacherName;
        department = newDepartment;
        phoneNumber = newPhoneNumber;
        noOfCourses = noOfCourses;
        courses = new int[noOfCourses];
        for (int i = 0; i < noOfCourses; i++)
        {
            courses[i] = newCourseCode[i];
        }
    }
    Teacher(const User &newUser, const Teacher &newTeacher) : User(newUser)
    {
        teacherName = newTeacher.teacherName;
        department = newTeacher.department;
        phoneNumber = newTeacher.phoneNumber;
        noOfCourses = newTeacher.noOfCourses;
        courses = new int[noOfCourses];
        for (int i = 0; i < noOfCourses; i++)
        {
            courses[i] = newTeacher.courses[i];
        }
    }

    // Setters
    void SetTeacherName(string newTeacherName)
    {
        teacherName = newTeacherName;
    }
    void SetDepartment(string newDepartment)
    {
        department = newDepartment;
    }
    void SetPhoneNumber(long long int newPhoneNumber)
    {
        phoneNumber = newPhoneNumber;
    }
    void SetTotalCourses(int noOfCourses)
    {
        noOfCourses = noOfCourses;
    }
    void SetCourseCodes(int *newCourseCode)
    {
        courses = new int[noOfCourses];
        for (int i = 0; i < noOfCourses; i++)
        {
            courses[i] = newCourseCode[i];
        }
    }

    // Getters
    string GetTeacherName()
    {
        return teacherName;
    }
    string GetDepartment()
    {
        return department;
    }
    long long int GetPhoneNumber()
    {
        return phoneNumber;
    }
    int GetTotalCourses()
    {
        return noOfCourses;
    }
    int *GetCourseCodes()
    {
        return courses;
    }
    void DeleteCourseCodes()
    {
        delete[] courses;
        courses = nullptr;
    }
    // operator overloading
    friend ostream &operator<<(ostream &out, const Teacher &newTeacher);
};
ostream &operator<<(ostream &out, Teacher &newTeacher)
{

    cout << newTeacher.getUsername() << ", ";
    cout << newTeacher.getPassword() << ", ";
    cout << newTeacher.GetTeacherName() << ", ";
    cout << newTeacher.GetDepartment() << ", ";
    cout << newTeacher.GetPhoneNumber() << ", ";
    cout << newTeacher.GetTotalCourses() << ",";
    int *tickets = newTeacher.GetCourseCodes();
    for (int j = 0; j < newTeacher.GetTotalCourses(); j++)
    {
        cout << " " << tickets[j];
    }
    cout << ".";

    return out;
}
class AcademicOfficer : public User
{
private:
    string academicOfficerName;

public:
    // constructors
    AcademicOfficer()
    {
        academicOfficerName[0] = '\0';
    }
    AcademicOfficer(string newName, string newPassword, string newAdminName) : User(newName, newPassword)
    {
        academicOfficerName = newAdminName;
    }
    AcademicOfficer(const User &newUser, const AcademicOfficer &newAdmin) : User(newUser)
    {
        academicOfficerName = newAdmin.academicOfficerName;
    }
    // setter
    void SetAdminName(string newAdminName)
    {
        academicOfficerName = newAdminName;
    }

    // getter
    string GetAdminName()
    {
        return academicOfficerName;
    }
};
class Program
{
private:
    string programCode;
    string programName;
    vector<PLO> plo;

public:
    Program()
    {
        programCode[0] = NULL;
        programName[0] = NULL;
        plo = NULL;
    }
    Program(string progCode, string progName, vector<PLO> newPLO)
    {
        programCode = progCode;
        programName = progName;
        plo = new vector<PLO>(newPLO);
    }
    ~Program();

    // setters
    void SetProgramCode(string code) { programCode = code; }
    void SetProgramName(string name) { programName = name; }

    // getters
    string GetProgramCode() { return programCode; }
    string GetProgramName() { return programName; }

    // Member Functions
    void AddPLO(PLO plo)
    {
    }
    void RemovePLO(PLO plo)
    {
    }
    void UpdatePLO(PLO plo)
    {
    }
    // operator overloading
    friend ostream &operator<<(ostream &output, const Program &prog);
};

class Course
{
private:
    string courseCode;
    string courseName;
    string topicName;
    PLO plo;
    vector<Question> question;

public:
    Course()
    {
        courseCode[0] = NULL;
        courseName[0] = NULL;
    }
    Course(string cCode, string cName)
    {
        courseCode = cCode;
        courseName = cName;
    }
    ~Course();

    // setters
    void SetCourseCode(string code) { courseCode = code; }
    void SetCourseName(string name) { courseName = name; }

    // getters
    string GetCourseCode() { return courseCode; }
    string GetCourseName() { return courseName; }

    // Member Functions
    void AddCLO(CLO plo)
    {
    }
    void RemoveCLO(CLO plo)
    {
    }
    void UpdateCLO(CLO plo)
    {
    }
};

class PLO
{
    string ploCode;
    string ploDescription;

public:
    PLO()
    {
        ploCode[0] = NULL;
        ploDescription[0] = NULL;
    }
    PLO(string plCode, string plName)
    {
        ploCode = plCode;
        ploDescription = plName;
    }
    ~PLO();

    // setters
    void SetPLOCode(string code) { ploCode = code; }
    void SetPLODesc(string desc) { ploDescription = desc; }

    // getters
    string GetPLOCode() { return ploCode; }
    string GetPLODesc() { return ploDescription; }

    // Member Functions
    void AddCLO(CLO plo)
    {
    }
    void RemoveCLO(CLO plo)
    {
    }
    void UpdateCLO(CLO plo)
    {
    }
};

class CLO
{
private:
    /* data */
public:
    CLO(/* args */);
    ~CLO();
};

CLO::CLO(/* args */)
{
}

CLO::~CLO()
{
}

class Question
{
private:
    string questionText;
    CLO testedCLO;

public:
    Question()
    {
        questionText[0] = NULL;
    }
    Question(string text, CLO clo)
    {
        questionText = text;
        testedCLO = clo;
    }

    // setters
    void setQuestionText(string t) { questionText = t; }
    void setTestedCLO(CLO c) { testedCLO = c; }

    // getter
    string getQuestionText() { return questionText; }
    CLO getTestedCLO() { return testedCLO; }
};

class Evalutation
{
private:
    string evaluationType;
    vector<CLO> relatedClos;
    vector<Question> questions;

public:
    Evalutation()
    {
        evaluationType[0] = NULL;
    }

    Evalutation(string type, vector<CLO> clos, vector<Question> quest)
    {
        evaluationType = type;
        relatedClos = clos;
        questions = quest;
    }

    // setters
    void setEvaluationType(string eType) { evaluationType = eType; }
    void setRelatedClo(vector<CLO> clo) { relatedClos = clo; }
    void setQuestions(vector<Question> que) { questions = que; }

    // getters
    string getEvaluationType() { return evaluationType; }
    vector<CLO> getRelatedCLOStructures() { return relatedClos; }
    int getNumberOfQuestions() { return questions.size(); }
    vector<Question> getQuestions() { return questions; }

    // add functions
    void addClo(CLO clo)
    {
        relatedClos.push_back(clo);
    }
    // remove clo by being given a clo
    bool removeClo(CLO clo)
    {
        for (int i = 0; i < relatedClos.size(); ++i)
        {
            if (relatedClos[i] == clo)
            {
                relatedClos.erase(relatedClos.begin() + i);
                return true;
            }
        }
        return false;
    };

    // update clo by using the cloCode of  the clo to find it in the list and then updating that clo with the new one
    bool updateCLO()

        void addQuestionToQuestionsList(Question que)
    {
        questions.push_back(que);
    }
};

/*********************************************FILE FUNCTIONS************************************************/

string InputAcademicOfficerFileName()
{
    string academicOfficerFileName;
    cout << "Enter the name of file containing records of Academic Officers (filename should have its file type at the end e.g file.txt): ";
    getline(cin, academicOfficerFileName, '\n');

    return academicOfficerFileName;
}
string InputTeacherFileName()
{
    string teacherFileName;
    cout << "Enter the name of file containing records of Academic Officers (filename should have its file type at the end e.g file.txt): ";
    getline(cin, teacherFileName, '\n');

    return teacherFileName;
}
string InputProgramFileName()
{
    string programFileName;
    cout << "Enter the name of file containing records of Academic Officers (filename should have its file type at the end e.g file.txt): ";
    getline(cin, programFileName, '\n');

    return programFileName;
}
string InputCourseFileName()
{
    string courseFileName;
    cout << "Enter the name of file containing records of Academic Officers (filename should have its file type at the end e.g file.txt): ";
    getline(cin, courseFileName, '\n');

    return courseFileName;
}
string InputPloFileName()
{
    string ploFileName;
    cout << "Enter the name of file containing records of Academic Officers (filename should have its file type at the end e.g file.txt): ";
    getline(cin, ploFileName, '\n');

    return ploFileName;
}
string InputCloFileName()
{
    string cloFileName;
    cout << "Enter the name of file containing records of Academic Officers (filename should have its file type at the end e.g file.txt): ";
    getline(cin, cloFileName, '\n');

    return cloFileName;
}

vector<AcademicOfficer> InputAcademicOfficerData(string) {}

vector<Teacher> InputTeacherData(string teacherFileName) {}
vector<Program> InputProgramData(string) {}
vector<Course> InputCourseData(string) {}
vector<PLO> InputPloData(string) {}
vector<CLO> InputCloData(string) {}

int main()
{
    // Get Teacher and Academic Officer data from file  and copy into arrays/vectors

    // login the user and compare it in both arrays(redundant)
    // add some codein username like T to signify teacher whilst A  to signify AO so you dont have to traverse both arrays

    string academicOfficerFile, teacherFile, programFile, courseFile, ploFile, cloFile;

    //  vector<AcademicOfficer> academicOfficerData;
    // vector<Teacher> teacherData;
    // vector<Program> programData;
    // vector<Course> courseData;
    // vector<PLO> ploData;
    // vector<CLO> cloData;

    // academicOfficerFile = InputAcademicOfficerFileName();
    // teacherFile = InputTeacherFileName();
    // programFile = InputProgramFileName();
    // courseFile = InputCourseFileName();
    // ploFile = InputPloFileName();
    // cloFile = InputCloFileName();

    // academicOfficerData = InputAcademicOfficerData(academicOfficerFile);
    // teacherData = InputTeacherData(teacherFile);
    // programData = InputProgramData(programFile);
    // courseData = InputCourseData(courseFile);
    // ploData = InputPloData(ploFile);
    // cloData = InputCloData(cloFile);

    // choice variables
    int userchoice = 0;

    userchoice = MainMenu();

    while (userchoice != 0)
    {
        if (userchoice == 1)
        {
        }
        else if (userchoice == 2)
        {
        }
        userchoice = MainMenu();
    }

    return 0;
}
