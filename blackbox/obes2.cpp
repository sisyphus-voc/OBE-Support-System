#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

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

    Question& operator=(Question other)
    {
        swap(questionId, other.questionId);
        swap(questionText, other.questionText);
        swap(cloCode, other.cloCode);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const Question& other) const
    {
        return questionId == other.questionId && questionText == other.questionText && cloCode == other.cloCode;
    }

    bool operator!=(const Question& other) const
    {
        return!(*this == other);
    }

    // Add CLO
    void addCLO(string newCLO) { cloCode = newCLO; }

    // Remove CLO
    void removeCLO() { cloCode = {}; }

    // Update CLO
    void updateCLO(string updateCLO, string newCLO) { updateCLO = newCLO; }

    // Print function
    void print() {
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
    string  ploCode;
    vector<Question*> questions;

public:
    // Constructors
    CLO() : cloCode(""), cloDescription(""), cloTopic(""), ploCode(), questions() {}

    CLO(string newCloCode, string newCloDescription, string newCloTopic, string newPloCode, vector<Question*> newQuestions) : cloCode(newCloCode), cloDescription(newCloDescription), cloTopic(newCloTopic), ploCode(newPloCode), questions(newQuestions) {}

    // Setters
    void setCloCode(string newCloCode) { cloCode = newCloCode; }
    void setCloDescription(string newCloDescription) { cloDescription = newCloDescription; }
    void setCloTopic(string newCloTopic) { cloTopic = newCloTopic; }
    void setPLO(string newPlo) { ploCode = newPlo; }
    void setQuestions(vector<Question*> newQuestions) { questions = newQuestions; }

    // Getters
    string getCloCode() { return cloCode; }
    string getCloDescription() { return cloDescription; }
    string getCloTopic() { return cloTopic; }
    string getPLO() { return ploCode; }
    vector<Question*> getQuestions() { return questions; }

    CLO& operator=(CLO other)
    {
        swap(cloCode, other.cloCode);
        swap(cloDescription, other.cloDescription);
        swap(cloTopic, other.cloTopic);
        swap(ploCode, other.ploCode);
        swap(questions, other.questions);
        return *this;
    }

    // Operator overloading for == and!=
    bool operator==(const CLO& other) const
    {
        return cloCode == other.cloCode && cloDescription == other.cloDescription && cloTopic == other.cloTopic && ploCode == other.ploCode && questions == other.questions;
    }

    bool operator!=(const CLO& other) const
    {
        return!(*this == other);
    }

    // Add Question
    void addQuestion(Question* newQuestion) { questions.push_back(newQuestion); }

    // Remove Question
    void removeQuestion(Question* removeQuestion)
    {
        auto it = find(questions.begin(), questions.end(), removeQuestion);
        if (it != questions.end())
        {
            questions.erase(it);
        }
    }

    // Update Question
    void updateQuestion(Question* updateQuestion, Question* newQuestion)
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
        cout << "PLO: "<< ploCode<<endl;
        cout << endl;
    }
    void printWithQuestions()
    {
        cout << "CLO Code: " << cloCode << endl;
        cout << "CLO Description: " << cloDescription << endl;
        cout << "CLO Topic: " << cloTopic << endl;
        cout << "PLO: " <<ploCode<<endl;
        cout << endl;
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
    if (cloCode!="")
    {
        cout << "CLO Code: " << cloCode << endl;
    }
    else
    {
        cout << "No assigned CLO\n";
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

// Function to read CLO data from a file and return a vector of CLO pointers
vector<CLO*> readCLOsFromFile(const string& filename)
{
    vector<CLO*> cloVector;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return cloVector;
    }

    string line;
    while (getline(file, line))
    {
        // Parse the line into the CLO data members
        size_t pos = 0;
        string cloCode = line.substr(0, line.find(','));
        line.erase(0, line.find(',') + 1);

        string cloDescription = line.substr(0, line.find(','));
        line.erase(0, line.find(',') + 1);

        string cloTopic = line.substr(0, line.find(','));
        line.erase(0, line.find(',') + 1);

        string ploCode = line.substr(0, line.find(','));
        line.erase(0, line.find(',') + 1);

       

        // Create a new CLO object with the parsed data
        CLO* clo = new CLO(cloCode, cloDescription, cloTopic, {}, {});

        // Add the CLO object to the vector
        cloVector.push_back(clo);


    }

    file.close();
    return cloVector;
}

// Function to read CLO data from a file and return a vector of CLO pointers
vector<Question*> readQuestionsFromFile(const string& filename)
{
    vector<Question*> questionVector;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return questionVector;
    }

    string line;
    while (getline(file, line))
    {
        // Parse the line into the CLO data members
        size_t pos = 0;
        string questionId = line.substr(0, line.find(','));
        line.erase(0, line.find(',') + 1);

        string questionText = line.substr(0, line.find(','));
        line.erase(0, line.find(',') + 1);

        string cloCode = line.substr(0, line.find(','));
        line.erase(0, line.find(',') + 1);

        
       


        // Create a new CLO object with the parsed data
        Question* question = new Question(questionId, questionText, cloCode);

        // Add the CLO object to the vector
        questionVector.push_back(question);


    }

    file.close();
    return questionVector;
}

int main()
{
    // Variable Declaration
    string academicOfficerFile, teacherFile, programFile, courseFile, ploFile, cloFile,questionFile;

    //  academicOfficerFile = InputAcademicOfficerFileName();
    // vector<AcademicOfficer*> officers;
    // officers = readAcademicOfficersFromFile(academicOfficerFile);
    // printAcademicOfficers(officers);
    cloFile = InputCloFileName();
    questionFile = InputQuestionsFileName();
    vector<Question*>questionData;
    questionData = readQuestionsFromFile(questionFile);

    vector<CLO*> cloData;
    cloData = readCLOsFromFile(cloFile);

    for (int i = 0; i < questionData.size(); i++)
    {
        questionData[i]->print();
    }
    for (int i = 0; i < cloData.size(); i++)
    {
        cloData[i]->print();
    }


    //    // Create a new Question object
    //Question question1("Q1", "Question 1 Text", new CLO("CLO1", "CLO1 Description", "CLO1 Topic", {}, {}));

    //// Test the setters
    //question1.setQuestionId("Q2");
    //question1.setQuestionText("Question 2 Text");
    //question1.setTestedCLO(new CLO("CLO2", "CLO2 Description", "CLO2 Topic", {}, {}));

    //// Test the getters
    //cout << "Question ID: " << question1.getQuestionId() << endl;
    //cout << "Question Text: " << question1.getQuestionText() << endl;
    //cout << "Tested CLO: " << question1.getTestedCLO()->getCloCode() << endl;

    //question1.print();

    //// Test the operator overloading for ==
    //Question question2("Q2", "Question 2 Text", new CLO("CLO2", "CLO2 Description", "CLO2 Topic", {}, {}));
    //if (question1 == question2)
    //{
    //    cout << "The questions are equal." << endl;
    //}
    //else
    //{
    //    cout << "The questions are not equal." << endl;
    //}

    //// Test the operator overloading for!=
    //Question question3("Q3", "Question 3 Text", new CLO("CLO3", "CLO3 Description", "CLO3 Topic", {}, {}));
    //if (question1 != question3)
    //{
    //    cout << "The questions are not equal." << endl;
    //}
    //else
    //{
    //    cout << "The questions are equal." << endl;
    //}

    //// Test the addCLO function
    //question1.addCLO(new CLO("CLO4", "CLO4 Description", "CLO4 Topic", {}, {}));
    //cout << "Add CLO func\n"; cout << question1.getTestedCLO();

    //// Test the removeCLO function
    //question1.removeCLO();

    //// Test the updateCLO function
    //question1.updateCLO(new CLO("CLO5", "CLO5 Description", "CLO5 Topic", {}, {}), new CLO("CLO6", "CLO6 Description", "CLO6 Topic", {}, {}));

    //// Test the print function
    //question1.print();

    //// Create a new CLO object
    //CLO clo1("CLO1", "CLO1 Description", "CLO1 Topic", {}, {});

    //// Test the setters
    //clo1.setCloCode("CLO2");
    //clo1.setCloDescription("CLO2 Description");
    //clo1.setCloTopic("CLO2 Topic");
    //clo1.setQuestions({ &question1 });

    //// Test the getters
    //cout << "CLO Code: " << clo1.getCloCode() << endl;
    //cout << "CLO Description: " << clo1.getCloDescription() << endl;
    //cout << "CLO Topic: " << clo1.getCloTopic() << endl;
    //cout << "PLO: ";
    //// clo1.getPLO()->print();
    //cout << endl;
    //cout << "Questions: " << endl;
    //for (auto question : clo1.getQuestions())
    //{
    //    question->print();
    //}

    //// Test the operator overloading for ==
    //CLO clo2("CLO2", "CLO2 Description", "CLO2 Topic", {}, { &question1 });
    //if (clo1 == clo2)
    //{
    //    cout << "The CLOs are equal." << endl;
    //}
    //else
    //{
    //    cout << "The CLOs are not equal." << endl;
    //}

    //// Test the operator overloading for!=
    //CLO clo3("CLO3", "CLO3 Description", "CLO3 Topic", {}, {});
    //if (clo1 != clo3)
    //{
    //    cout << "The CLOs are not equal." << endl;
    //}
    //else
    //{
    //    cout << "The CLOs are equal." << endl;
    //}

    //// Test the addQuestion function
    //clo1.addQuestion(&question2);

    //// Test the removeQuestion function
    //clo1.removeQuestion(&question2);

    //// Test the```updateQuestion function
    //clo1.updateQuestion(&question1, &question3);

    //// Test the print function
    //clo1.print();



    // academicOfficerFile = InputAcademicOfficerFileName();
    // teacherFile = InputTeacherFileName();
    // programFile = InputProgramFileName();
    // courseFile = InputCourseFileName();
    // ploFile = InputPloFileName();
    // cloFile = InputCloFileName();

    return 0;
}
