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
    void removeQuestion(Question *removeQuestion)
    {
        auto it = find(questions.begin(), questions.end(), removeQuestion);
        if (it != questions.end())
        {
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

// Search
//  Function to search for a CLO object by cloCode and return its index
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
int main()
{
    // Variable Declaration
    string academicOfficerFile, teacherFile, programFile, courseFile, ploFile, cloFile, questionFile;

    // Input file names
    cloFile = "clo.txt";
    questionFile = "questions.txt";
    ploFile = "plo.txt";
    courseFile = "courses.txt";
    programFile = "programs.txt";
    // cloFile = InputCloFileName();
    // questionFile = InputQuestionsFileName();
    // ploFile = InputPloFileName();
    // courseFile=InputCourseFileName();
    // programFile=InputProgramFileName();

    // Vector to pointer of objects
    vector<Question *> questionData;
    vector<CLO *> cloData;
    vector<PLO *> ploData;
    vector<Course *> courseData;
    vector<Program *> programData;

    questionData = readQuestionsFromFile(questionFile);
    cloData = readCLOsFromFile(cloFile);
    ploData = readPLOsFromFile(ploFile);
    courseData = readCoursesFromFile(courseFile);
    programData = readProgramsFromFile(programFile);

    addQuestionObjsInCLOs(questionData, cloData);
    addCloObjsInPLOs(cloData, ploData);
    addCloObjsInCourses(cloData, courseData);
    addPLOsInPrograms(ploData, programData);
    addCoursesInPrograms(courseData, programData);

    for (Program *program : programData)
    {
        program->print();
    }

    return 0;
}
