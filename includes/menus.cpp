#include <iostream>
#include <vector>

using namespace std;

int getChoice()
{
    int choice = 0;

    cin >> choice;
    while (!cin.good())
    {
        cout << "Invalid Input (Wrong Data Type)\n";
        cin.clear();
        // cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "=>";
        cin >> choice;
    }
    return choice;
}

int MainMenu()
{
    int choice = 0;
    system("CLS");
    cout << "Welcome to the Objective Based Education Support System!!" << endl;
    cout << endl;
    cout << "Choose one of the options down below!" << endl;
    cout << "1. For Admin" << endl;
    cout << "2. For Teacher" << endl;
    cout << "0. To exit the program" << endl;
    cout << "=> ";
    choice = getChoice();
    return choice;
}

int AdminMenu()
{
    int choice = 0;
    system("CLS");
    cout << "Choose whatever you would like to do:" << endl;

    cout << "1. Programs" << endl;
    cout << "2. Courses" << endl;
    cout << "3. PLO" << endl;
    cout << "4. CLO" << endl;
    cout << "0. Exit" << endl;

    cout << "=> ";
    choice = getChoice();
    return choice;
}

int ActionMenu(string obj)
{
    int choice = 0;
    system("CLS");
    cout << "Choose whatever you would like to do:" << endl;

    cout << "1. Add " << obj << endl;
    cout << "2. Remove " << obj << endl;
    cout << "3. Update " << obj << endl;
    cout << "0. Exit " << obj << endl;

    cout << "=> ";
    choice = getChoice();
    return choice;
}

int ProgramMenu()
{
    string menuType;
    menuType = "Program";
    ActionMenu(menuType);
}
int CourseMenu()
{
    string menuType;
    menuType = "Course";
    ActionMenu(menuType);
}
int PloMenu()
{
    string menuType;
    menuType = "PLO";
    ActionMenu(menuType);
}
int CloMenu()
{
    string menuType;
    menuType = "CLO";
    ActionMenu(menuType);
}

int TeacherMenu()
{
    int choice = 0;
    system("CLS");
    cout << "Choose whatever you would like to do:" << endl;

    cout << "1. Add CLO Topic" << endl;
    cout << "2. Add Evaluation" << endl;
    cout << "3. Associate CLO with evaluation" << endl;
    cout << "0. Exit" << endl;

    cout << "=> ";
    choice = getChoice();
    return choice;
    return 0;
}

int EvaluationMenu()
{
    int choice = 0;
    system("CLS");
    cout << "Choose whatever you would like to do:" << endl;

    cout << "1. Add Quiz" << endl;
    cout << "2. Add Exam" << endl;
    cout << "3. Add Project" << endl;
    cout << "3. Add Assignment" << endl;
    cout << "0. Exit " << endl;

    cout << "=> ";
    choice = getChoice();
    return choice;
}
