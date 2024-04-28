#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class PLO;
class CLO;
class Question;

// tasks classes
class Question
{
private:
    string questionId;
    string questionText;
    string cloCode;

public:
    // Constructors
    Question() : questionId(""), questionText(""), cloCode() {}

    Question(string newQuestionId, string newQuestionText, string newCloCode) : questionId(newQuestionId), questionText(newQuestionText), cloCode(newCloCode) {}

    // Setters
    void setQuestionId(string newQuestionId) { questionId = newQuestionId; }
    void setQuestionText(string newQuestionText) { questionText = newQuestionText; }
    void setTestedCLO(string newTestedCLO) { cloCode = newTestedCLO; }

    // Getters
    string getQuestionId() { return questionId; }
    string getQuestionText() { return questionText; }
    string getTestedCLO() { return cloCode; }

    Question &operator=(Question other)
    {
        swap(questionId, other.questionId);
        swap(questionText, other.questionText);
        swap(cloCode, other.cloCode);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const Question &other) const
    {
        return questionId == other.questionId && questionText == other.questionText && cloCode == other.cloCode;
    }

    bool operator!=(const Question &other) const
    {
        return !(*this == other);
    }

    // Add CLO
    void addCLO(string newCLO) { cloCode = newCLO; }

    // Remove CLO
    void removeCLO() { cloCode = {}; }

    // Update CLO
    void updateCLO(string updateCLO, string newCLO) { updateCLO = newCLO; }

    // Print function
    void print()
    {
        cout << "Question ID: " << questionId << endl;
        cout << "Question Text: " << questionText << endl;
    }
    void printWithCLO();
};
class CLO
{
private:
    string cloCode;
    string cloDescription;
    string cloTopic;
    string ploCode;
    string courseCode;
    vector<Question *> questions;

public:
    // Constructors
    CLO() : cloCode(""), cloDescription(""), cloTopic(""), ploCode(""), courseCode(""), questions() {}

    CLO(string newCloCode, string newCloDescription, string newCloTopic, string newPloCode, string newCourseCode, vector<Question *> newQuestions) : cloCode(newCloCode), cloDescription(newCloDescription), cloTopic(newCloTopic), ploCode(newPloCode), courseCode(newCourseCode), questions(newQuestions) {}

    // Setters
    void setCloCode(string newCloCode) { cloCode = newCloCode; }
    void setCloDescription(string newCloDescription) { cloDescription = newCloDescription; }
    void setCloTopic(string newCloTopic) { cloTopic = newCloTopic; }
    void setPloCode(string newPlo) { ploCode = newPlo; };
    void setCourseCode(string newCourseCode) { courseCode = newCourseCode; }
    void setQuestions(vector<Question *> newQuestions) { questions = newQuestions; }

    // Getters
    string getCloCode() { return cloCode; }
    string getCloDescription() { return cloDescription; }
    string getCloTopic() { return cloTopic; }
    string getPloCode() { return ploCode; }
    string getCourseCode() { return courseCode; }
    vector<Question *> getQuestions() { return questions; }

    CLO &operator=(CLO other)
    {
        swap(cloCode, other.cloCode);
        swap(cloDescription, other.cloDescription);
        swap(cloTopic, other.cloTopic);
        swap(ploCode, other.ploCode);
        swap(courseCode, other.courseCode);
        swap(questions, other.questions);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const CLO &other) const
    {
        return cloCode == other.cloCode && cloDescription == other.cloDescription && cloTopic == other.cloTopic && ploCode == other.ploCode && questions == other.questions;
    }

    bool operator!=(const CLO &other) const
    {
        return !(*this == other);
    }

    // Add Question
    void addQuestion(Question *newQuestion) { questions.push_back(newQuestion); }

    // Remove Question
    bool removeQuestion(Question *removeQuestion)
    {
        auto it = find(questions.begin(), questions.end(), removeQuestion);
        if (it != questions.end())
        {
            // Delete the actual question object
            delete *it;
            // Erase the pointer from the vector
            questions.erase(it);
        }
    }

    // Update Question
    void updateQuestion(Question *updateQuestion, Question *newQuestion)
    {
        auto it = find(questions.begin(), questions.end(), updateQuestion);
        if (it != questions.end())
        {
            *it = newQuestion;
        }
    }
    bool isTested()
    {
        if (questions.size() > 1)
        {
            return true;
        }
        else
            return false;
    }

    // Print function
    void print()
    {
        cout << "CLO Code: " << cloCode << endl;
        cout << "CLO Description: " << cloDescription << endl;
        cout << "CLO Topic: " << cloTopic << endl;
        cout << "PLO: " << ploCode << endl;
        cout << "Course: " << courseCode << endl;
        cout << endl;
    }
    void printWithQuestions()
    {
        cout << endl
             << "CLO Code: " << cloCode << endl;
        cout << "CLO Description: " << cloDescription << endl;
        cout << "CLO Topic: " << cloTopic << endl;
        cout << "PLO: " << ploCode << endl;
        cout << "Course: " << courseCode << endl;
        cout << "Questions: " << endl;
        for (auto question : questions)
        {
            question->print();
        }
    }
};

void Question::printWithCLO()
{
    cout << "Question ID: " << questionId << endl;
    cout << "Question Text: " << questionText << endl;
    if (cloCode != "")
    {
        cout << "CLO Code: " << cloCode << endl;
    }
    else
    {
        cout << "No assigned CLO\n";
    }
}

class PLO
{
private:
    string ploCode;
    string ploDescription;
    string programCode;
    vector<CLO *> clos;

public:
    // Constructors
    PLO() : ploCode(""), ploDescription(""), programCode(""), clos() {}

    PLO(string newPloCode, string newPloDescription, string newProgramCode, vector<CLO *> newClos) : ploCode(newPloCode), ploDescription(newPloDescription), programCode(newProgramCode), clos(newClos) {}

    // Setters
    void setPLOCode(string newPloCode) { ploCode = newPloCode; }
    void setPLODescription(string newPloDescription) { ploDescription = newPloDescription; }
    void setProgramCode(string newProgramCode) { programCode = newProgramCode; }
    void setCLOs(vector<CLO *> newClos) { clos = newClos; }

    // Getters
    string getPLOCode() { return ploCode; }
    string getPLODescription() { return ploDescription; }
    string getProgramCode() { return programCode; }
    vector<CLO *> getCLOs() { return clos; }

    // Operator overloading for =
    PLO &operator=(PLO other)
    {
        swap(ploCode, other.ploCode);
        swap(ploDescription, other.ploDescription);
        swap(programCode, other.programCode);
        swap(clos, other.clos);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const PLO &other) const
    {
        return ploCode == other.ploCode && ploDescription == other.ploDescription && programCode == other.programCode && clos == other.clos;
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
    void updateCLO(CLO *updateCLO, CLO *newCLO) { *updateCLO = *newCLO; }

    // Print function
    void print()
    {
        cout << "PLO Code: " << ploCode << endl;
        cout << "PLO Description: " << ploDescription << endl;
        cout << "Program:  " << programCode << endl;
        cout << "Number of CLOs: " << clos.size() << "\n";
        if (clos.empty())
            cout << "No CLOs in this PLO.\n\n";
        else
        {
            cout << "CLOs: " << endl;
            for (auto clo : clos)
            {
                clo->print();
            }
        }
    }
};

class Course
{
private:
    string courseCode;
    string courseName;
    string programCode;
    vector<CLO *> clos;

public:
    // Constructors
    Course() : courseCode(""), courseName(""), programCode(""), clos() {}

    Course(string newCourseCode, string newCourseName, string newProgramCode, vector<CLO *> newClos) : courseCode(newCourseCode), courseName(newCourseName), programCode(newProgramCode), clos(newClos) {}

    // Setters
    void setCourseCode(string newCourseCode) { courseCode = newCourseCode; }
    void setCourseName(string newCourseName) { courseName = newCourseName; }
    void setProgramCode(string newProgramCode) { programCode = newProgramCode; }
    void setCLOs(vector<CLO *> newClos) { clos = newClos; }

    // Getters
    string getCourseCode() { return courseCode; }
    string getCourseName() { return courseName; }
    string getProgramCode() { return programCode; }
    vector<CLO *> getCLOs() { return clos; }

    // Operator overloading for =
    Course &operator=(Course other)
    {
        swap(courseCode, other.courseCode);
        swap(courseName, other.courseName);
        swap(programCode, other.programCode);
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
    void updateCLO(CLO *updateCLO, CLO *newCLO) { *updateCLO = *newCLO; }

    // Print function
    void print()
    {
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Program: " << programCode << endl;
        cout << "CLOs: " << endl;
        for (auto clo : clos)
        {
            clo->print();
        }
    }
};
class Program
{
private:
    string programCode;
    string programName;
    vector<Course *> courses;
    vector<PLO *> plos;

public:
    // Constructors
    Program() : programCode(""), programName(""), plos(), courses() {}

    Program(string newProgramCode, string newProgramName, vector<PLO *> newPlos, vector<Course *> newCourses) : programCode(newProgramCode), programName(newProgramName), plos(newPlos), courses(newCourses) {}

    // Setters
    void setProgramCode(string newProgramCode) { programCode = newProgramCode; }
    void setProgramName(string newProgramName) { programName = newProgramName; }
    void setCourses(vector<Course *> newCourses) { courses = newCourses; }
    void setPLOs(vector<PLO *> newPlos) { plos = newPlos; }

    // Getters
    string getProgramCode() { return programCode; }
    string getProgramName() { return programName; }
    vector<Course *> getCourse() { return courses; }
    vector<PLO *> getPLOs() { return plos; }

    // Operator overloading for =
    Program &operator=(Program other)
    {
        swap(programCode, other.programCode);
        swap(programName, other.programName);
        swap(courses, other.courses);
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
    void updatePLO(PLO *updatePLO, PLO *newPLO) { *updatePLO = *newPLO; }

    // Add Course
    void addCourse(Course *newCourse) { courses.push_back(newCourse); }

    // Remove Course
    void removeCourse(Course *removeCourse) { courses.erase(remove(courses.begin(), courses.end(), removeCourse)); }

    // Update Course
    void updateCourse(Course *updateCourse, Course *newCourse) { *updateCourse = *newCourse; }

    // Print function
    void print()
    {
        cout << "Program Code: " << programCode << endl;
        cout << "Program Name: " << programName << endl;
        cout << "Courses: " << endl;
        for (auto c : courses)
        {
            c->print();
        }
        cout << "PLOs: " << endl;
        for (auto plo : plos)
        {
            plo->print();
        }
    }
};

class Evaluation
{
private:
    string evaluationType;
    string evaluationCode;
    vector<CLO *> relatedCLOs;
    vector<Question *> questions;

public:
    // Constructors
    Evaluation() : evaluationType(""), evaluationCode(""), relatedCLOs(), questions() {}

    Evaluation(string newEvaluationType, string newEvaluationCode, vector<CLO *> newRelatedCLOs, vector<Question *> newQuestions) : evaluationType(newEvaluationType), evaluationCode(newEvaluationCode), relatedCLOs(newRelatedCLOs), questions(newQuestions) {}

    // Setters
    void setEvaluationType(string newEvaluationType) { evaluationType = newEvaluationType; }
    void setEvaluationCode(string newEvaluationCode) { evaluationCode = newEvaluationCode; }
    void setRelatedCLOs(vector<CLO *> newRelatedCLOs) { relatedCLOs = newRelatedCLOs; }
    void setQuestions(vector<Question *> newQuestions) { questions = newQuestions; }

    // Getters
    string getEvaluationType() { return evaluationType; }
    string getEvaluationCode() { return evaluationCode; }
    vector<CLO *> getRelatedCLOs() { return relatedCLOs; }
    vector<Question *> getQuestions() { return questions; }

    Evaluation &operator=(Evaluation other)
    {
        swap(evaluationType, other.evaluationType);
        swap(evaluationCode, other.evaluationCode);
        swap(relatedCLOs, other.relatedCLOs);
        swap(questions, other.questions);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const Evaluation &other) const
    {
        return evaluationType == other.evaluationType && evaluationCode == other.evaluationCode && relatedCLOs == other.relatedCLOs && questions == other.questions;
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
    // Add CLO
    void addCLO(CLO *newCLO) { relatedCLOs.push_back(newCLO); }

    // Remove CLO
    void removeCLO(CLO *removeCLO) { relatedCLOs.erase(remove(relatedCLOs.begin(), relatedCLOs.end(), removeCLO)); }

    // Update CLO
    void updateCLO(CLO *updateCLO, CLO *newCLO) { *updateCLO = *newCLO; }

    // Print function
    void print()
    {
        cout << endl
             << "Evaluation Type: " << evaluationType << endl;
        cout << "Evaluation Code: " << evaluationCode << endl;
        cout << "Related CLOs: " << endl;
        for (auto clo : relatedCLOs)
        {
            cout << clo->getCloCode() << " ";
        }
        cout << "\nQuestions: " << endl;
        for (auto question : questions)
        {
            // cout << question->getTestedCLO() << endl;
            cout << question->getQuestionId() << "\t(" << question->getTestedCLO() << ")" << endl;
            cout << question->getQuestionText() << endl;
        }
    }
};

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

    // operator overloading for assignment
    User &operator=(const User &other)
    {
        if (this != &other)
        {
            username = other.username;
            password = other.password;
            userType = other.userType;
        }
        return *this;
    }

    // operator overloading for equality
    bool operator==(const User &other) const
    {
        return username == other.username && password == other.password && userType == other.userType;
    }

    // operator overloading for inequality
    bool operator!=(const User &other) const
    {
        return !(*this == other);
    }
    // Print Function
    void print()
    {
        cout << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "User Type: " << userType << endl;
    }
};

class AcademicOfficer : public User
{
private:
    string academicOfficer;
    string department;
    string phoneNumber;

public:
    // Constructors
    AcademicOfficer() : User("", "", "AcademicOfficer"), academicOfficer(""), department(""), phoneNumber("") {}

    AcademicOfficer(string newUsername, string newPassword, string newAcademicOfficerName, string newDepartment, string newPhoneNumber) : User(newUsername, newPassword, "AcademicOfficer"), academicOfficer(newAcademicOfficerName), department(newDepartment), phoneNumber(newPhoneNumber) {}

    // Setters
    void setAcademicOfficerName(string newAcademicOfficerName) { academicOfficer = newAcademicOfficerName; }
    void setDepartment(string newDepartment) { department = newDepartment; }
    void setPhoneNumber(string newPhoneNumber) { phoneNumber = newPhoneNumber; }

    // Getters
    string getAcademicOfficerName() { return academicOfficer; }
    string getDepartment() { return department; }
    string getPhoneNumber() { return phoneNumber; }

    // Print function
    void print()
    {
        User::print();
        cout << "Academic Officer Name: " << academicOfficer << endl;
        cout << "Department: " << department << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }
};

class Teacher : public User
{
private:
    string teacherName;
    string department;
    string phoneNumber;       // Changed to string
    vector<Course *> courses; // Vector of Course pointers

public:
    // Constructors
    Teacher() : User("", "", "Teacher"), teacherName(""), department(""), phoneNumber(""), courses() {}

    Teacher(string newUsername, string newPassword, string newTeacherName, string newDepartment, string newPhoneNumber, vector<Course *> newCourses) : User(newUsername, newPassword, "Teacher"), teacherName(newTeacherName), department(newDepartment), phoneNumber(newPhoneNumber), courses(newCourses) {}

    // Setters
    void setTeacherName(string newTeacherName) { teacherName = newTeacherName; }
    void setDepartment(string newDepartment) { department = newDepartment; }
    void setPhoneNumber(string newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setCourses(vector<Course *> newCourses) { courses = newCourses; }

    // Getters
    string getTeacherName() const { return teacherName; }
    string getDepartment() const { return department; }
    string getPhoneNumber() const { return phoneNumber; }
    vector<Course *> getCourses() const { return courses; }

    // Add Course
    void addCourse(Course *newCourse) { courses.push_back(newCourse); }

    // Remove Course
    void removeCourse(Course *removeCourse) { courses.erase(remove(courses.begin(), courses.end(), removeCourse)); }

    // Update Course
    void updateCourse(Course *updateCourse, Course *newCourse) { *updateCourse = *newCourse; }

    // operator overloading for assignment
    Teacher &operator=(const Teacher &other)
    {
        if (this != &other)
        {
            // Call the base class assignment operator
            User::operator=(other);

            // Assign other members
            teacherName = other.teacherName;
            department = other.department;
            phoneNumber = other.phoneNumber;

            // Deep copy courses
            courses.clear();
            for (Course *course : other.courses)
            {
                courses.push_back(new Course(*course));
            }
        }
        return *this;
    }

    // operator overloading for equality
    bool operator==(const Teacher &other) const
    {
        // Compare all member variables for equality
        return static_cast<const User &>(*this) == static_cast<const User &>(other) &&
               teacherName == other.teacherName &&
               department == other.department &&
               phoneNumber == other.phoneNumber &&
               courses == other.courses;
    }
    // operator overloading for inequality
    bool operator!=(const Teacher &other) const
    {
        return !(*this == other);
    }
    // Print function
    void print()
    {
        User::print();
        cout << "Teacher Name: " << teacherName << endl;
        cout << "Department: " << department << endl;
        cout << "Phone Number: " << phoneNumber << endl;

        cout << "Courses: " << endl;
        for (auto course : courses)
        {

            cout << course->getCourseCode() << endl
                 << course->getCourseName() << endl;
        }
    }
};
template <typename T>
void displayAllObjects(const vector<T *> &objects)
{
    for (const auto &obj_ptr : objects)
    {

        obj_ptr->print();
    }
}
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
string InputEvaluationsFileName()
{
    string evaluationFileName;
    cout << "Enter the name of file containing records of Evaluations (filename should have its file type at the end e.g file.txt): ";
    getline(cin, evaluationFileName, '\n');

    return evaluationFileName;
}
string InputCloFileName()
{
    string cloFileName;
    cout << "Enter the name of file containing records of CLOs (filename should have its file type at the end e.g file.txt): ";
    getline(cin, cloFileName, '\n');

    return cloFileName;
}
string InputQuestionsFileName()
{
    string questionFileName;
    cout << "Enter the name of file containing records of Questions (filename should have its file type at the end e.g file.txt): ";
    getline(cin, questionFileName, '\n');

    return questionFileName;
}

// Read Data from file functions.
vector<Question *> readQuestionsFromFile(const string &filename)
{
    vector<Question *> questionVector;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return questionVector;
    }

    string line;
    while (getline(file, line))
    {
        // Use stringstream to parse the line
        stringstream ss(line);
        string questionId, questionText, cloCode;

        // Read each comma-separated value
        getline(ss, questionId, ',');
        getline(ss, questionText, ',');
        getline(ss, cloCode, '.');

        // Create a new Question object with the parsed data
        Question *question = new Question(questionId, questionText, cloCode);

        // Add the Question object to the vector
        questionVector.push_back(question);
    }

    file.close();
    return questionVector;
}
vector<CLO *> readCLOsFromFile(const string &filename)
{
    vector<CLO *> cloVector;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return cloVector;
    }

    string line;
    while (getline(file, line))
    {
        // Use stringstream to parse the line
        stringstream ss(line);
        string cloCode, cloDescription, cloTopic, ploCode, courseCode;

        // Read each comma-separated value
        getline(ss, cloCode, ',');
        getline(ss, cloDescription, ',');
        getline(ss, cloTopic, ',');
        getline(ss, ploCode, ',');
        getline(ss, courseCode, '.');

        // Create a new CLO object with the parsed data
        CLO *clo = new CLO(cloCode, cloDescription, cloTopic, ploCode, courseCode, {});

        // Add the CLO object to the vector
        cloVector.push_back(clo);
    }

    file.close();
    return cloVector;
}
vector<Evaluation *> readEvaluationsFromFile(const string &filename)
{
    vector<Evaluation *> evaluationVector;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return evaluationVector;
    }

    string line;
    while (getline(file, line))
    {
        // Use stringstream to parse the line
        stringstream ss(line);
        string evaluationType, evaluationCode, questionCodes;

        // Read each comma-separated value
        getline(ss, evaluationType, ',');
        getline(ss, evaluationCode, ',');
        getline(ss, questionCodes, '.');

        // Tokenize questionCodes
        stringstream qss(questionCodes);
        string questionCode;
        vector<Question *> questions;
        while (getline(qss, questionCode, ','))
        {
            // Find the Question object with the corresponding code and add it to the questions vector

            Question *question = new Question(questionCode, "", {});
            if (question)
            {
                questions.push_back(question);
            }
        }

        // Create a new Evaluation object with the parsed data
        Evaluation *evaluation = new Evaluation(evaluationType, evaluationCode, {}, questions);

        // Add the Evaluation object to the vector
        evaluationVector.push_back(evaluation);
    }

    file.close();
    return evaluationVector;
}

vector<PLO *> readPLOsFromFile(const string &filename)
{
    vector<PLO *> ploVector;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return ploVector;
    }

    string line;
    while (getline(file, line))
    {
        // Use stringstream to parse the line
        stringstream ss(line);
        string ploCode, ploDescription, programCode;

        // Read each comma-separated value
        getline(ss, ploCode, ',');
        getline(ss, ploDescription, ',');
        getline(ss, programCode, '.');

        // Create a new PLO object with the parsed data
        PLO *plo = new PLO(ploCode, ploDescription, programCode, {});

        // Add the PLO object to the vector
        ploVector.push_back(plo);
    }

    file.close();
    return ploVector;
}
vector<Course *> readCoursesFromFile(const string &filename)
{
    vector<Course *> courseVector;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return courseVector;
    }

    string line;

    while (getline(file, line))
    {
        // Use stringstream to parse the line
        stringstream ss(line);
        string courseCode, courseName, programCode;

        // Read each comma-separated value
        getline(ss, courseCode, ',');
        getline(ss, courseName, ',');
        getline(ss, programCode, '.');

        // Create a new Course object with the parsed data
        Course *course = new Course(courseCode, courseName, programCode, {});

        // Add the Course object to the vector
        courseVector.push_back(course);
    }

    file.close();
    return courseVector;
}

// Function to read program data from file
vector<Program *> readProgramsFromFile(const string &filename)
{
    vector<Program *> programVector;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return programVector;
    }

    string line;
    while (getline(file, line))
    {
        // Use stringstream to parse the line
        stringstream ss(line);
        string programCode, programName;

        // Read each comma-separated value
        getline(ss, programCode, ',');
        getline(ss, programName, '.');

        // Create a new Program object with the parsed data
        Program *program = new Program(programCode, programName, {}, {});

        // Add the Program object to the vector
        programVector.push_back(program);
    }

    file.close();
    return programVector;
}
// Function to read academic officer data from file
vector<AcademicOfficer *> readAcademicOfficersFromFile(const string &filename)
{
    vector<AcademicOfficer *> academicOfficers;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return academicOfficers;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string username, password, academicOfficerName, department, phoneNumber;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, academicOfficerName, ',');
        getline(ss, department, ',');
        getline(ss, phoneNumber, '.');

        AcademicOfficer *ao = new AcademicOfficer(username, password, academicOfficerName, department, phoneNumber);

        academicOfficers.push_back(ao);
    }

    file.close();
    return academicOfficers;
}
vector<Teacher *> readTeachersFromFile(const string &filename)
{
    vector<Teacher *> teachers;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return teachers;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string username, password, teacherName, department, phoneNumber, courseCodes;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, teacherName, ',');
        getline(ss, department, ',');
        getline(ss, phoneNumber, ','); // Use ',' as delimiter for phoneNumber
        getline(ss, courseCodes, '.'); // Use '.' as delimiter for courseCodes

        // Tokenize courseCodes using ','
        stringstream css(courseCodes);
        string courseCode;
        vector<Course *> courses;

        while (getline(css, courseCode, ','))
        {
            // Create Course object with the given code
            Course *course = new Course(courseCode, "", "", {});
            if (course)
            {
                courses.push_back(course);
            }
        }

        // Create Teacher object and add it to teachers vector
        Teacher *teacher = new Teacher(username, password, teacherName, department, phoneNumber, courses);
        teachers.push_back(teacher);
    }

    file.close();
    return teachers;
}

// Search
//  Function to search for a CLO object by cloCode and return its index
int searchQuestionIndexByCode(const vector<Question *> &questionData, const string &code)
{
    for (size_t i = 0; i < questionData.size(); ++i)
    {
        if (questionData[i]->getQuestionId() == code)
        {
            return i; // Return the index of the found CLO object
        }
    }
    return -1; // Return -1 if no matching CLO object is found
}

int searchCLOIndexByCode(const vector<CLO *> &cloData, const string &code)
{
    for (size_t i = 0; i < cloData.size(); ++i)
    {
        if (cloData[i]->getCloCode() == code)
        {
            return i; // Return the index of the found CLO object
        }
    }
    return -1; // Return -1 if no matching CLO object is found
}
//  Function to search for a PLO object by ploCode and return its index
int searchPLOIndexByCode(const vector<PLO *> &ploData, const string &code)
{
    for (size_t i = 0; i < ploData.size(); ++i)
    {
        if (ploData[i]->getPLOCode() == code)
        {
            return i; // Return the index of the found CLO object
        }
    }
    return -1; // Return -1 if no matching CLO object is found
}

int searchCourseIndexByCode(const vector<Course *> &courseData, const string &code)
{
    for (size_t i = 0; i < courseData.size(); ++i)
    {
        if (courseData[i]->getCourseCode() == code)
        {
            return i; // Return the index of the found course object
        }
    }
    return -1; // Return -1 if no matching course object is found
}

int searchProgramIndexByCode(const vector<Program *> &programData, const string &code)
{
    for (size_t i = 0; i < programData.size(); ++i)
    {
        if (programData[i]->getProgramCode() == code)
        {
            return i; // Return the index of the found program object
        }
    }
    return -1; // Return -1 if no matching program object is found
}

// Point Question objects to their corresponding CLO
void addQuestionObjsInCLOs(vector<Question *> &questionData, vector<CLO *> &cloData)
{

    for (Question *question : questionData)
    {
        int idx = searchCLOIndexByCode(cloData, question->getTestedCLO());
        cloData[idx]->addQuestion(question);
    }
}
// Point CLO objects to their corresponding PLO
void addCloObjsInPLOs(vector<CLO *> &cloData, vector<PLO *> &ploData)
{

    for (CLO *clo : cloData)
    {
        int idx = searchPLOIndexByCode(ploData, clo->getPloCode());
        ploData[idx]->addCLO(clo);
    }
}
void addCloObjsInCourses(vector<CLO *> &cloData, vector<Course *> &courseData)
{
    for (CLO *clo : cloData)
    {
        int idx = searchCourseIndexByCode(courseData, clo->getCourseCode());
        if (idx != -1)
        {
            courseData[idx]->addCLO(clo);
        }
        else
        {
            cerr << "Course with code " << clo->getCourseCode() << " not found." << endl;
        }
    }
}
void addPLOsInPrograms(vector<PLO *> &ploData, vector<Program *> &programData)
{
    for (PLO *plo : ploData)
    {
        int idx = searchProgramIndexByCode(programData, plo->getProgramCode());
        if (idx != -1)
        {
            programData[idx]->addPLO(plo);
        }
        else
        {
            cerr << "Program with code " << plo->getProgramCode() << " not found." << endl;
        }
    }
}
void addCoursesInPrograms(vector<Course *> &courseData, vector<Program *> &programData)
{
    for (Course *course : courseData)
    {
        int idx = searchProgramIndexByCode(programData, course->getProgramCode());
        if (idx != -1)
        {
            programData[idx]->addCourse(course);
        }
        else
        {
            cerr << "Program with code " << course->getProgramCode() << " not found." << endl;
        }
    }
}
void addQsandClosInEvaluations(vector<Question *> &questionData, vector<CLO *> &cloData, vector<Evaluation *> &evaluationData)
{
    for (Evaluation *evaluation : evaluationData)
    {
        vector<Question *> questions = evaluation->getQuestions();
        for (Question *question : questions)
        {
            int idx = searchQuestionIndexByCode(questionData, question->getQuestionId());
            if (idx != -1)
            {
                evaluation->updateQuestion(question, questionData[idx]);
                evaluation->addCLO(cloData[searchCLOIndexByCode(cloData, question->getTestedCLO())]); // add tested CLO to evaluation
                ;
            }
            else
            {
                cerr << "Question with code " << question->getQuestionId() << " not found." << endl;
            }
        }
    }
}
void addCoursesInTeacher(vector<Course *> &courseData, vector<Teacher *> &teacherData)
{
    for (Teacher *teacher : teacherData)
    {
        vector<Course *> courses = teacher->getCourses();
        for (Course *course : courses)
        {
            int idx = searchCourseIndexByCode(courseData, course->getCourseCode());
            if (idx != -1)
            {
                teacher->updateCourse(course, courseData[idx]);
            }
            else
            {
                cerr << "Course with code " << course->getCourseCode() << " not found." << endl;
            }
        }
    }
}
template <typename T>
bool SignIn(const vector<T *> &data)
{
    string username;
    cout << "Username: ";
    cin >> username;

    string password;
    cout << "Password: ";
    cin >> password;
    cin.ignore();

    bool isFound = false;
    for (const auto &item : data)
    {
        if (item->getUsername() == username && item->getPassword() == password)
        {
            isFound = true;
            item->print();
            break;
        }
    }
    if (!isFound)
    {
        cout << "User or Password incorrect!" << endl;
    }
    return isFound;
}
bool SignUp(vector<Teacher *> &teacherData)
{

    bool duplicateUsername = false;
    string username;
    do
    {

        cout << "Username: ";
        cin >> username;
        int checkUsr = 0;
        for (auto i : teacherData)
        {
            if (i->getUsername() == username)
            {
                checkUsr++;
            }
        }
        if (checkUsr > 0)
        {
            cout << "This Username already exists." << endl;
            duplicateUsername = true;
        }
        else
            duplicateUsername = false;
    } while (duplicateUsername);

    string password, confPass;
    cout << "Password(>8 characters): ";
    cin >> password;
    cout << "Confirm Password: ";
    confPass = "";
    cin >> confPass;
    while (password != confPass || password.length() < 8)
    {
        cout << "Invalid input! Please try again." << endl;
        cout << "Password: ";
        cin >> password;
        cout << "Confirm Password: ";
        confPass = "";
        cin >> confPass;
    }
    cin.ignore();
    string name, dept, phoneNum;
    cout << "Name: ";
    getline(cin, name);

    cout << "Department: ";
    getline(cin, dept);

    cout << "Phone Number: ";
    getline(cin, phoneNum);
    Teacher *temp = new Teacher(username, password, name, dept, phoneNum, {});
    teacherData.push_back(temp);
    system("CLS");
    cout << "Your account has been created, " << temp->getTeacherName() << "!" << endl;
    temp->print();

    return true;
}
bool CLOTested(vector<CLO *> cloData)
{
    // get clo code as input
    string cLOCode;
    int idx = -1;
    bool validInput = false;
    while (!validInput)
    {
        cout << "Enter the CLO Code you want to test:" << endl;
        cin >> cLOCode;
        idx = searchCLOIndexByCode(cloData, cLOCode);

        if (idx != -1)
            validInput = true;
        else
        {
            cout << "Invalid Input! Please try again." << endl;
        }
    }
    return cloData[idx]->isTested();
}
bool CLOTested(vector<Course *> courseData)
{
    // get course code as input
    string courseCode;
    int courseIdx = -1;
    bool found = false;

    while (!found)
    {
        cout << "Please enter the Course ID of the course that contains the CLO you are testing: " << endl;
        cin >> courseCode;
        courseIdx = searchCourseIndexByCode(courseData, courseCode);
        if (courseIdx != -1)
            found = true;
        else
            cout << "Invalid Course ID. Please Try Again.\n"
                 << endl;
    }
    vector<CLO *> closForThisCourse = courseData[courseIdx]->getCLOs();

    if (closForThisCourse.empty())
    {
        cout << "The selected course does not contain any CLOs.\n";
        return false;
    }
    else
    {

        for (CLO *c : closForThisCourse)
        {
            if (c->isTested())
                continue;
            else if (!c->isTested())
            {
                return false;
            }
        }
        return true;
    }
}
void CoursesInPlo(vector<Program *> progData, vector<PLO *> ploData)
{
    // get plocode as input
    string pLOCode;
    int idx = -1;
    bool validInput = false;
    while (!validInput)
    {
        cout << "Enter the PLO Code you want to test:" << endl;
        cin >> pLOCode;
        idx = searchPLOIndexByCode(ploData, pLOCode);

        if (idx != -1)
            validInput = true;
        else
        {
            cout << "Invalid Input! Please try again." << endl;
        }
    }
    int progIdx = searchProgramIndexByCode(progData, ploData[idx]->getProgramCode());
    vector<Course *> coursesInProgram = progData[progIdx]->getCourse();
    for (auto c : coursesInProgram)
    {
        if (coursesInProgram.empty())
        {
            cout << "The program does not contain this PLO!" << endl;
            break;
        }
        else
        {
            cout << c->getCourseCode() << endl;
        }
    }
}
bool AddNewProgram(vector<Program *> &progData)
{

    string code, name;
    // get Data of new program from user

    bool isDuplicate = false;
    while (!isDuplicate)
    {
        cout << "Please enter Program Code: ";
        cin >> code;
        if (searchProgramIndexByCode(progData, code) != -1)
        { // duplicate found
            cout << "This Program already exists. Try again.\n";
            isDuplicate = true;
            continue;
        }
        else
            isDuplicate = false;
        break;
    }

    cout << "Please enter Program Name: ";
    cin.ignore();
    getline(cin, name);

    Program *newProg = new Program(code, name, {}, {});
    progData.push_back(newProg); // add the new program to data base
    system("CLS");
    cout << "Program has been added!" << endl;
    cout << "Program Code: " << code << endl;
    cout << "Program Name: " << name << endl;

    return true;
}
bool AddNewCourse(vector<Course *> &courseData)
{

    string code, name;
    // get Data of new course from user

    bool isDuplicate = false;
    while (!isDuplicate)
    {
        cout << "Please enter Course Code: ";
        cin >> code;
        if (searchCourseIndexByCode(courseData, code) != -1)
        { // duplicate found
            cout << "This Course already exists. Try again.\n";
            isDuplicate = true;
            continue;
        }
        else
            isDuplicate = false;
        break;
    }

    cout << "Please enter Course Name: ";
    cin.ignore();
    getline(cin, name);

    Course *newCourse = new Course(code, name, {}, {});
    courseData.push_back(newCourse); // add the new course to data base
    system("CLS");
    cout << "Course has been added!" << endl;
    cout << "Course Code: " << code << endl;
    cout << "Course Name: " << name << endl;

    return true;
}
bool AddNewPlo(vector<PLO *> &ploData, vector<Program *> &progData)
{

    string code, desc, progCode;
    int progIdx;
    // get Data of new PLO from user

    cout << "Please select Program this PLO belongs to:\n";
    displayAllObjects(progData);
    // get program code input from user
    bool validInput = false;
    while (!validInput)
    {
        cout << "Enter Program Code: ";
        cin >> progCode;
        progIdx = searchProgramIndexByCode(progData, progCode);

        if (progIdx == -1)
        {
            cerr << "Error: Invalid Program Code\n";
            // ask y/n
            validInput = false;
        }
        else
        {
            validInput = true;
            break;
        }
    }

    bool isDuplicate = false;
    while (!isDuplicate)
    {
        cout << "Please enter PLO Code: ";
        cin >> code;
        if (searchPLOIndexByCode(ploData, code) != -1)
        { // duplicate found
            cout << "This PLO already exists. Try again.\n";
            isDuplicate = true;
            continue;
        }
        else
            isDuplicate = false;
        break;
    }

    cout << "Please enter PLO Description: ";
    cin.ignore();
    getline(cin, desc);

    PLO *newPLO = new PLO(code, desc, progCode, {});
    ploData.push_back(newPLO);         // add the new PLO to data base
    progData[progIdx]->addPLO(newPLO); // add the new PLO to program's list of PLOS

    system("CLS");
    cout << "PLO has been added!" << endl;
    cout << "PLO Code: " << code << endl;
    cout << "PLO Description: " << desc << endl;

    return true;
}
void AddNewClo(vector<CLO *> &cloData, vector<PLO *> &ploData, vector<Course *> &courseData)
{
    string code, desc, ploCode, courseCode;
    int ploIdx, courseIdx;
    cout << "Please select Course this CLO belongs to:\n";
    displayAllObjects(courseData);
    // get program code input from user
    bool validInput = false;
    while (!validInput)
    {
        cout << "Enter Course Code: ";
        cin >> courseCode;
        courseIdx = searchCourseIndexByCode(courseData, courseCode);

        if (courseIdx == -1)
        {
            cerr << "Error: Invalid Program Code\n";
            // ask y/n
            validInput = false;
        }
        else
        {
            validInput = true;
            break;
        }
    }
    system("cls");
    cout << "Please select PLO this CLO belongs to:\n";
    displayAllObjects(ploData);
    // get program code input from user
    validInput = false;
    while (!validInput)
    {
        cout << "Enter PLO Code: ";
        cin >> ploCode;
        ploIdx = searchPLOIndexByCode(ploData, ploCode);

        if (ploIdx == -1)
        {
            cerr << "Error: Invalid Program Code\n";
            // ask y/n
            validInput = false;
        }
        else
        {
            validInput = true;
            break;
        }
    }
    bool isDuplicate = false;
    while (true)
    {
        cout << "Please enter CLO Code: ";
        cin >> code;

        if (searchCLOIndexByCode(cloData, code) != -1)
        {
            cout << "This CLO already exists. Try again.\n";
            isDuplicate = true;
        }
        else
        {
            isDuplicate = false;
            break;
        }
    }

    cin.ignore(); // Clear the buffer

    cout << "Please enter CLO Description: ";
    getline(cin, desc);

    CLO *newClo = new CLO(code, desc, "", ploCode, courseCode, {});
    cloData.push_back(newClo);
    ploData[ploIdx]->addCLO(newClo);
    courseData[courseIdx]->addCLO(newClo);

    system("CLS");
    cout << "CLO has been added!" << endl;
    cout << "CLO Code: " << code << endl;
    cout << "CLO Description: " << desc << endl;
    system("pause");
    system("CLS");
}
// Remove Functions-------------------------------------------------

void RemoveClo(vector<CLO *> &cloData, vector<Evaluation *> &evalData, vector<Course *> &courseData, vector<PLO *> &ploData)
{
    string code;
    int cloIdx, evalIdx, courseIdx, ploIdx;
    cout << "Please select the CLO :\n";
    displayAllObjects(cloData);

    bool validInput = false;
    while (!validInput)
    {
        cout << "Enter CLO Code: ";
        cin >> code;
        cloIdx = searchCLOIndexByCode(cloData, code);

        if (cloIdx == -1)
        {
            cerr << "Error: Invalid Program Code\n";
            // ask y/n
            validInput = false;
        }
        else
        {
            validInput = true;
            break;
        }
    }
    // remove from courses
    courseIdx = searchCourseIndexByCode(courseData, cloData[cloIdx]->getCourseCode());
    courseData[courseIdx]->removeCLO(cloData[cloIdx]);

    ploIdx = searchPLOIndexByCode(ploData, cloData[cloIdx]->getPloCode());
    ploData[ploIdx]->removeCLO(cloData[cloIdx]);

    vector<Question *> temp = cloData[cloIdx]->getQuestions();

    for (auto q : temp)
    {

        for (auto e : evalData)
        {
            e->removeQuestion(q);
        }
    }
    cout << "meh\n";
    for (auto q : temp)
    {
        cloData[cloIdx]->removeQuestion(q);
    }

    for (auto e : evalData)
    {
        e->removeCLO(cloData[cloIdx]);
    }

    cloData.erase(cloData.begin() + cloIdx);
    cout << "CLO " << code << "has been removed successfully\n";

    system("Pause");
    system("cls");
}
// TeacherFunctions---------------------------------------------------
void AddCloTopic(vector<CLO *> &cloData)
{
    string code, topic;
    int cloIdx;
    cout << "Please select the CLO :\n";
    displayAllObjects(cloData);

    bool validInput = false;
    while (!validInput)
    {
        cout << "Enter CLO Code: ";
        cin >> code;
        cloIdx = searchCLOIndexByCode(cloData, code);

        if (cloIdx == -1)
        {
            cerr << "Error: Invalid Program Code\n";
            // ask y/n
            validInput = false;
        }
        else
        {
            validInput = true;
            break;
        }
    }
    system("cls");
    // Clear the input buffer before reading the topic
    cin.ignore();
    cout << "Enter  Topic: ";
    getline(cin, topic);

    cloData[cloIdx]->setCloTopic(topic);
    cout << "CLO Topic has been added!" << endl;
    cout << "CLO Code: " << cloData[cloIdx]->getCloCode() << endl;
    cout << "CLO Description: " << cloData[cloIdx]->getCloDescription() << endl;
    cout << "CLO Topic: " << cloData[cloIdx]->getCloTopic() << endl;
    system("pause");
    system("CLS");
}
int main()
{
    // Variable Declaration
    string academicOfficerFile, teacherFile, programFile, courseFile, ploFile, cloFile, questionFile, evaluationFile;

    // Input file names
    cloFile = "clo.txt";
    questionFile = "questions.txt";
    ploFile = "plo.txt";
    courseFile = "courses.txt";
    programFile = "programs.txt";
    evaluationFile = "evaluation.txt";
    academicOfficerFile = "ao.txt";
    teacherFile = "teachers.txt";
    // cloFile = InputCloFileName();
    // questionFile = InputQuestionsFileName();
    // ploFile = InputPloFileName();
    // courseFile=InputCourseFileName();
    // programFile=InputProgramFileName();
    // academicOfficerFile=InputAcademicOfficerFileName();
    // teacherFile=InputTeacherFileName();

    // Vector to pointer of objects
    vector<Question *> questionData;
    vector<CLO *> cloData;
    vector<PLO *> ploData;
    vector<Course *> courseData;
    vector<Program *> programData;
    vector<Evaluation *> evaluationData;
    vector<AcademicOfficer *> academicOfficerData;
    vector<Teacher *> teacherData;

    questionData = readQuestionsFromFile(questionFile);
    cloData = readCLOsFromFile(cloFile);
    ploData = readPLOsFromFile(ploFile);
    courseData = readCoursesFromFile(courseFile);
    programData = readProgramsFromFile(programFile);
    evaluationData = readEvaluationsFromFile(evaluationFile);
    academicOfficerData = readAcademicOfficersFromFile(academicOfficerFile);
    teacherData = readTeachersFromFile(teacherFile);

    addQuestionObjsInCLOs(questionData, cloData);
    addCloObjsInPLOs(cloData, ploData);
    addCloObjsInCourses(cloData, courseData);
    addPLOsInPrograms(ploData, programData);
    addCoursesInPrograms(courseData, programData);
    addQsandClosInEvaluations(questionData, cloData, evaluationData);
    addCoursesInTeacher(courseData, teacherData);

    // SignIn(academicOfficerData);
    // SignIn(teacherData);
    // SignUp(teacherData);

    // cout << CLOTested(cloData) << endl;
    // cout << CLOTested(courseData) << endl;
    /// CoursesInPlo(programData, ploData);

    // Add Functions
    // AddNewProgram(programData);
    // AddNewPlo(ploData, programData); // must have a mentioned
    // AddNewClo(cloData, ploData, courseData); // must have PLO and course

    // AddCloTopic(cloData);

    // Remove Functions

    // RemoveProgram(programData);
    // get program code as input, search it to get index, erase it.

    RemoveClo(cloData, evaluationData, courseData, ploData);
    for (auto p : cloData)
    {
        p->print();
    }
    system("Pause");
    system("cls");

    for (auto p : ploData)
    {
        p->print();
    }
    system("Pause");
    system("cls");
    for (auto p : courseData)
    {
        p->print();
    }
    system("Pause");
    system("cls");
    for (auto p : questionData)
    {
        p->print();
    }
    system("Pause");
    system("cls");
    for (auto p : evaluationData)
    {
        p->print();
    }
    system("Pause");
    system("cls");
    // RemoveClo(cloData);

    // Update Functions

    return 0;
}
