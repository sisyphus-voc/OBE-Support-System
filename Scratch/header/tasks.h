#include <iostream>
#include <vector>

using namespace std;

class PLO
{
private:
    string ploCode;
    string ploDescription;
    vector<CLO> cloVect;

public:
    // constructor
    PLO(string, string, vector<CLO>);

    // setters
    void setPloCode(string);
    void setPloDesc(string);
    void setcloVect(vector<CLO>);

    // getters
    string getPlocode();
    string getPloDesc();
    vector<CLO> getCloVect();

    void addClo(CLO);
    void removeClo(CLO);
    void updateClo(CLO);
    vector<Course> getAllCourses();
};

class CLO
{
private:
    string cloCode;
    string cloDescription;
    vector<PLO> ploVect;
    vector<Question> questionVect;

public:
    // constructor
    CLO(string, string);

    // setters
    void setCloCode(string);
    void setCloDesc(string);

    // getters
    string getClocode();
    string getCloDesc();

    void addQuestion(Question);
    void removeQuestion(Question);
    void updateQuestion(Question);
};

class Program
{
private:
    string programCode;
    string programDesc;
    vector<PLO> ploVect;

public:
    // constructor
    Program(string, string);

    // setters
    void setProgramCode(string);
    void setProgramDesc(string);

    // getters
    string getProgramCode();
    string getProgramDesc();

    void addPlo(PLO);
    void removePlo(PLO);
    void updatePlo(PLO);
};

class Course
{

private:
    string courseCode;
    string courseDesc;
    vector<CLO> cloVect;

public:
    // constructor
    Course(string, string);

    // setters
    void setCourseCode(string);
    void setCourseDesc(string);

    // getters
    string getCourseCode();
    string getCourseDesc();

    void addClo(CLO);
    void removeClo(CLO);
    void updateClo(CLO);
    bool isCloTested(CLO);
};

class Evaluation
{
private:
    string evaluationType;
    vector<CLO> relatedCloVect;
    vector<Question> questionVect;

public:
    // constructor
    Evaluation(string);

    // setters
    void setEvaluationType(string);

    // getters
    string getEvaluationType();

    void addQuestion(Question);
    void removeQuestion(Question);
    void updateQuestion(Question);
};

class Question
{
private:
    string questionText;
    CLO testedCLO;

public:
    // constructor
    Question(string, CLO);

    // setters
    void setQuestionText(string);
    void setTestedClo(CLO);

    // getters
    string getQuestionText();
};