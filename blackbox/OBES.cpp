#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

class Teacher;
class AcademicOfficer;
class Program;
class Course;
class PLO;
class CLO;
class Question;
class Evaluation;
// actors
class User
{
private:
    string username;
    string password;
    string userType;

public:
    // constructors
    User()
    {
        username[0] = '\0';
        password[0] = '\0';
        userType[0] = '\0';
    }
    User(string newName, string newPassword, string newType)
    {
        username = newName;
        password = newPassword;
        userType = newType;
    }
    User(const User &newUser)
    {
        username = newUser.username;
        password = newUser.password;
        userType = newUser.userType;
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
    void setUserType(string newType)
    {
        userType = newType;
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
    string getUserType()
    {
        return userType;
    }

    bool operator==(const User &newUser)
    {
        if (username == newUser.username && password == newUser.password && userType == newUser.userType)
        {
            return true;
        }
        else
            return false;
    }
    bool operator!=(const User &newUser)
    {
        if (username != newUser.username && password != newUser.password && userType != newUser.userType)
        {
            return true;
        }
        else
            return false;
    }
    // Print Function
    void print()
    {
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "User Type: " << userType << endl;
    }
};

class Teacher : public User
{
private:
    string teacherName;
    string department;
    long long int phoneNumber;
    int noOfCourses;
    vector<Course *> courses; // Vector of Course pointers

public:
    // Constructors
    Teacher() : User("", "", "Teacher"), teacherName(""), department(""), phoneNumber(0), noOfCourses(0), courses() {}

    Teacher(string newUsername, string newPassword, string newTeacherName, string newDepartment, long long int newPhoneNumber, int newNoOfCourses, vector<Course *> newCourses) : User(newUsername, newPassword, "Teacher"), teacherName(newTeacherName), department(newDepartment), phoneNumber(newPhoneNumber), noOfCourses(newNoOfCourses), courses(newCourses) {}

    // Setters
    void setTeacherName(string newTeacherName) { teacherName = newTeacherName; }
    void setDepartment(string newDepartment) { department = newDepartment; }
    void setPhoneNumber(long long int newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setNoOfCourses(int newNoOfCourses) { noOfCourses = newNoOfCourses; }
    void setCourses(vector<Course *> newCourses) { courses = newCourses; }

    // Getters
    string getTeacherName() { return teacherName; }
    string getDepartment() { return department; }
    long long int getPhoneNumber() { return phoneNumber; }
    int getNoOfCourses() { return noOfCourses; }
    vector<Course *> getCourses() { return courses; }

    // Add Course
    void addCourse(Course *newCourse) { courses.push_back(newCourse); }

    // Remove Course
    void removeCourse(Course *removeCourse) { courses.erase(remove(courses.begin(), courses.end(), removeCourse)); }

    // Update Course
    void updateCourse(Course *updateCourse, Course *newCourse) { updateCourse = newCourse; }

    // Print function
    void print()
    {
        User::print();
        cout << "Teacher Name: " << teacherName << endl;
        cout << "Department: " << department << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Number of Courses: " << noOfCourses << endl;

        cout << "Courses: " << endl;
        for (auto course : courses)
        {
            course->print();
        }
    }
};

class AcademicOfficer : public User
{
private:
    string academicOfficer;
    string department;
    long long int phoneNumber;

public:
    // Constructors
    AcademicOfficer() : User("", "", "AcademicOfficer"), academicOfficer(""), department(""), phoneNumber(0) {}

    AcademicOfficer(string newUsername, string newPassword, string newAcademicOfficerName, string newDepartment, long long int newPhoneNumber) : User(newUsername, newPassword, "AcademicOfficer"), academicOfficer(newAcademicOfficerName), department(newDepartment), phoneNumber(newPhoneNumber) {}

    // Setters
    void setAcademicOfficerName(string newAcademicOfficerName) { academicOfficer = newAcademicOfficerName; }
    void setDepartment(string newDepartment) { department = newDepartment; }
    void setPhoneNumber(long long int newPhoneNumber) { phoneNumber = newPhoneNumber; }

    // Getters
    string getAcademicOfficerName() { return academicOfficer; }
    string getDepartment() { return department; }
    long long int getPhoneNumber() { return phoneNumber; }

    // Print function
    void print()
    {
        User::print();
        cout << "Academic Officer Name: " << academicOfficer << endl;
        cout << "Department: " << department << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }
};

// tasks classes
class Program
{
private:
    string programCode;
    string programName;
    vector<PLO *> plos;

public:
    // Constructors
    Program() : programCode(""), programName(""), plos() {}

    Program(string newProgramCode, string newProgramName, vector<PLO *> newPlos) : programCode(newProgramCode), programName(newProgramName), plos(newPlos) {}

    // Setters
    void setProgramCode(string newProgramCode) { programCode = newProgramCode; }
    void setProgramName(string newProgramName) { programName = newProgramName; }
    void setPLOs(vector<PLO *> newPlos) { plos = newPlos; }

    // Getters
    string getProgramCode() { return programCode; }
    string getProgramName() { return programName; }
    vector<PLO *> getPLOs() { return plos; }

    // Operator overloading for =
    Program &operator=(Program other)
    {
        swap(programCode, other.programCode);
        swap(programName, other.programName);
        swap(plos, other.plos);
        return *this;
    }
    // Operator overloading for == and!=
    bool operator==(const Program &other) const
    {
        return programCode == other.programCode && programName == other.programName && plos == other.plos;
    }

    bool operator!=(const Program &other) const
    {
        return !(*this == other);
    }

    // Add PLO
    void addPLO(PLO *newPLO) { plos.push_back(newPLO); }

    // Remove PLO
    void removePLO(PLO *removePLO) { plos.erase(remove(plos.begin(), plos.end(), removePLO)); }

    // Update PLO
    void updatePLO(PLO *updatePLO, PLO *newPLO) { updatePLO = newPLO; }

    // Print function
    void print()
    {
        cout << "Program Code: " << programCode << endl;
        cout << "Program Name: " << programName << endl;
        cout << "PLOs: " << endl;
        for (auto plo : plos)
        {
            plo->print();
        }
    }
};

class Course
{
private:
    string courseCode;
    string courseName;
    vector<CLO *> clos;

public:
    // Constructors
    Course() : courseCode(""), courseName(""), clos() {}

    Course(string newCourseCode, string newCourseName, vector<CLO *> newClos) : courseCode(newCourseCode), courseName(newCourseName), clos(newClos) {}

    // Setters
    void setCourseCode(string newCourseCode) { courseCode = newCourseCode; }
    void setCourseName(string newCourseName) { courseName = newCourseName; }
    void setCLOs(vector<CLO *> newClos) { clos = newClos; }

    // Getters
    string getCourseCode() { return courseCode; }
    string getCourseName() { return courseName; }
    vector<CLO *> getCLOs() { return clos; }

    // Operator overloading for =
    Course &operator=(Course other)
    {
        swap(courseCode, other.courseCode);
        swap(courseName, other.courseName);
        swap(clos, other.clos);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const Course &other) const
    {
        return courseCode == other.courseCode && courseName == other.courseName && clos == other.clos;
    }

    bool operator!=(const Course &other) const
    {
        return !(*this == other);
    }

    // Add CLO
    void addCLO(CLO *newCLO) { clos.push_back(newCLO); }

    // Remove CLO
    void removeCLO(CLO *removeCLO) { clos.erase(remove(clos.begin(), clos.end(), removeCLO)); }

    // Update CLO
    void updateCLO(CLO *updateCLO, CLO *newCLO) { updateCLO = newCLO; }

    // Print function
    void print()
    {
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "CLOs: " << endl;
        for (auto clo : clos)
        {
            clo->print();
        }
    }
};

class PLO
{
private:
    string ploCode;
    string ploDescription;
    vector<CLO *> clos;

public:
    // Constructors
    PLO() : ploCode(""), ploDescription(""), clos() {}

    PLO(string newPloCode, string newPloDescription, vector<CLO *> newClos) : ploCode(newPloCode), ploDescription(newPloDescription), clos(newClos) {}

    // Setters
    void setPLOCode(string newPloCode) { ploCode = newPloCode; }
    void setPLODescription(string newPloDescription) { ploDescription = newPloDescription; }
    void setCLOs(vector<CLO *> newClos) { clos = newClos; }

    // Getters
    string getPLOCode() { return ploCode; }
    string getPLODescription() { return ploDescription; }
    vector<CLO *> getCLOs() { return clos; }

    // Operator overloading for =
    PLO &operator=(PLO other)
    {
        swap(ploCode, other.ploCode);
        swap(ploDescription, other.ploDescription);
        swap(clos, other.clos);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const PLO &other) const
    {
        return ploCode == other.ploCode && ploDescription == other.ploDescription && clos == other.clos;
    }

    bool operator!=(const PLO &other) const
    {
        return !(*this == other);
    }

    // Add CLO
    void addCLO(CLO *newCLO) { clos.push_back(newCLO); }

    // Remove CLO
    void removeCLO(CLO *removeCLO) { clos.erase(remove(clos.begin(), clos.end(), removeCLO)); }

    // Update CLO
    void updateCLO(CLO *updateCLO, CLO *newCLO) { updateCLO = newCLO; }

    // Print function
    void print()
    {
        cout << "PLO Code: " << ploCode << endl;
        cout << "PLO Description: " << ploDescription << endl;
        cout << "CLOs: " << endl;
        for (auto clo : clos)
        {
            clo->print();
        }
    }
};

class CLO
{
private:
    string cloCode;
    string cloDescription;
    string cloTopic;
    PLO plo;
    vector<Question *> questions;

public:
    // Constructors
    CLO() : cloCode(""), cloDescription(""), cloTopic(""), plo(), questions() {}

    CLO(string newCloCode, string newCloDescription, string newCloTopic, PLO newPlo, vector<Question *> newQuestions) : cloCode(newCloCode), cloDescription(newCloDescription), cloTopic(newCloTopic), plo(newPlo), questions(newQuestions) {}

    // Setters
    void setCloCode(string newCloCode) { cloCode = newCloCode; }
    void setCloDescription(string newCloDescription) { cloDescription = newCloDescription; }
    void setCloTopic(string newCloTopic) { cloTopic = newCloTopic; }
    void setPLO(PLO newPlo) { plo = newPlo; }
    void setQuestions(vector<Question *> newQuestions) { questions = newQuestions; }

    // Getters
    string getCloCode() { return cloCode; }
    string getCloDescription() { return cloDescription; }
    string getCloTopic() { return cloTopic; }
    PLO getPLO() { return plo; }
    vector<Question *> getQuestions() { return questions; }

    CLO &operator=(CLO other)
    {
        swap(cloCode, other.cloCode);
        swap(cloDescription, other.cloDescription);
        swap(cloTopic, other.cloTopic);
        swap(plo, other.plo);
        swap(questions, other.questions);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const CLO &other) const
    {
        return cloCode == other.cloCode && cloDescription == other.cloDescription && cloTopic == other.cloTopic && plo == other.plo && questions == other.questions;
    }

    bool operator!=(const CLO &other) const
    {
        return !(*this == other);
    }

    // Add Question
    void addQuestion(Question *newQuestion) { questions.push_back(newQuestion); }

    // Remove Question
    void removeQuestion(Question *removeQuestion) { questions.erase(remove(questions.begin(), questions.end(), removeQuestion)); }

    // Update Question
    void updateQuestion(Question *updateQuestion, Question *newQuestion) { updateQuestion = newQuestion; }

    // Print function
    void print()
    {
        cout << "CLO Code: " << cloCode << endl;
        cout << "CLO Description: " << cloDescription << endl;
        cout << "CLO Topic: " << cloTopic << endl;
        cout << "PLO: ";
        plo.print();
        cout << endl;
        cout << "Questions: " << endl;
        for (auto question : questions)
        {
            question->print();
        }
    }
};

class Question
{
private:
    string questionText;
    vector<CLO *> testedCLO;

public:
    // Constructors
    Question() : questionText(""), testedCLO() {}

    Question(string newQuestionText, vector<CLO *> newTestedCLO) : questionText(newQuestionText), testedCLO(newTestedCLO) {}

    // Setters
    void setQuestionText(string newQuestionText) { questionText = newQuestionText; }
    void setTestedCLO(vector<CLO *> newTestedCLO) { testedCLO = newTestedCLO; }

    // Getters
    string getQuestionText() { return questionText; }
    vector<CLO *> getTestedCLO() { return testedCLO; }

    Question &operator=(Question other)
    {
        swap(questionText, other.questionText);
        swap(testedCLO, other.testedCLO);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const Question &other) const
    {
        return questionText == other.questionText && testedCLO == other.testedCLO;
    }

    bool operator!=(const Question &other) const
    {
        return !(*this == other);
    }

    // Add CLO
    void addCLO(CLO *newCLO) { testedCLO.push_back(newCLO); }

    // Remove CLO
    void removeCLO(CLO *removeCLO) { testedCLO.erase(remove(testedCLO.begin(), testedCLO.end(), removeCLO)); }

    // Update CLO
    void updateCLO(CLO *updateCLO, CLO *newCLO) { *updateCLO = *newCLO; }

    // Print function
    void print()
    {
        cout << "Question Text: " << questionText << endl;
        cout << "Tested CLOs: " << endl;
        for (auto clo : testedCLO)
        {
            clo->print();
        }
    }
};

class Evaluation
{
private:
    string evaluationType;
    vector<CLO *> relatedCLOs;
    vector<Question *> questions;

public:
    // Constructors
    Evaluation() : evaluationType(""), relatedCLOs(), questions() {}

    Evaluation(string newEvaluationType, vector<CLO *> newRelatedCLOs, vector<Question *> newQuestions) : evaluationType(newEvaluationType), relatedCLOs(newRelatedCLOs), questions(newQuestions) {}

    // Setters
    void setEvaluationType(string newEvaluationType) { evaluationType = newEvaluationType; }
    void setRelatedCLOs(vector<CLO *> newRelatedCLOs) { relatedCLOs = newRelatedCLOs; }
    void setQuestions(vector<Question *> newQuestions) { questions = newQuestions; }

    // Getters
    string getEvaluationType() { return evaluationType; }
    vector<CLO *> getRelatedCLOs() { return relatedCLOs; }
    vector<Question *> getQuestions() { return questions; }

    Evaluation &operator=(Evaluation other)
    {
        swap(evaluationType, other.evaluationType);
        swap(relatedCLOs, other.relatedCLOs);
        swap(questions, other.questions);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const Evaluation &other) const
    {
        return evaluationType == other.evaluationType && relatedCLOs == other.relatedCLOs && questions == other.questions;
    }

    bool operator!=(const Evaluation &other) const
    {
        return !(*this == other);
    }

    // Add Question
    void addQuestion(Question *newQuestion) { questions.push_back(newQuestion); }

    // Remove Question
    void removeQuestion(Question *removeQuestion) { questions.erase(remove(questions.begin(), questions.end(), removeQuestion)); }

    // Update Question
    void updateQuestion(Question *updateQuestion, Question *newQuestion) { *updateQuestion = *newQuestion; }

    // Print function
    void print()
    {
        cout << "Evaluation Type: " << evaluationType << endl;
        cout << "Related CLOs: " << endl;
        for (auto clo : relatedCLOs)
        {
            clo->print();
        }
        cout << "Questions: " << endl;
        for (auto question : questions)
        {
            question->print();
        }
    }
};

/****************************File Functions******************/

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

int main()
{
    // Variable Declaration
    string academicOfficerFile, teacherFile, programFile, courseFile, ploFile, cloFile;

    // academicOfficerFile = InputAcademicOfficerFileName();
    // teacherFile = InputTeacherFileName();
    // programFile = InputProgramFileName();
    // courseFile = InputCourseFileName();
    // ploFile = InputPloFileName();
    // cloFile = InputCloFileName();

    return 0;
}
