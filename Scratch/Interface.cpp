#include <iostream>
#include <string>

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
    cout << "5. Check Whether a CLO has been tested or not(in two different questions)" << endl;
    cout << "6. Check whether all ClO's of a given course have been tested" << endl;
    cout << "6. Given a PLO generate a list of all the relevant courses" << endl;
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

int main()
{
    int mainChoice;
    int adminChoice;
    int actionChoice;
    int teacherChoice;
    int evaluationChoice;

    do
    {
        mainChoice = MainMenu();

        switch (mainChoice)
        {
        case 1: // Admin
            system("cls");
            // SignIn(academicOfficerData);
            do
            {
                adminChoice = AdminMenu();
                switch (adminChoice)
                {
                case 1: // Programs
                    do
                    {
                        actionChoice = ActionMenu("Program");
                        switch (actionChoice)
                        {
                        case 1:
                            cout << "Add\n"; // AddNewProgram(programData);
                            // prompt the user to enter the details about the program
                            // use those details to create and object and push it into the
                            // program data vector, then append it into the main file.
                            break;
                        case 2:
                            cout << "Remove\n"; // RemoveProgram();
                            // get the programCode from the user, go to the program data vector, delete the said vector and then replace the file data with the new updated vector.
                            break;
                        case 3:
                            cout << "Update"; // UpdateProgram();
                            // get program code of the vector that needs to be updated, make a copy of that vector and get info that needs to be changed, change it in the copy and swap the vectors in the main vector file and append

                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                        }
                    } while (actionChoice != 0);
                    break;
                case 2: // Courses
                    do
                    {
                        actionChoice = ActionMenu("Course");
                        switch (actionChoice)
                        {
                        case 1:
                            cout << "Add\n"; // AddNewCourse(courseData);
                            break;
                        case 2:
                            cout << "Remove\n"; // RemoveCourse();
                            break;
                        case 3:
                            cout << "Update"; // UpdateCourse();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                        }
                    } while (actionChoice != 0);
                    break;
                case 3: // PLO
                    do
                    {
                        actionChoice = ActionMenu("PLO");
                        switch (actionChoice)
                        {
                        case 1:
                            cout << "Add\n"; // AddNewPlo(ploData, programData); // must have a mentioned
                            break;
                        case 2:
                            cout << "Remove\n"; // RemovePLO();
                            break;
                        case 3:
                            cout << "Update"; // UpdatePLO();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                        }
                    } while (actionChoice != 0);
                    break;
                case 4: // CLO
                    do
                    {
                        actionChoice = ActionMenu("CLO");
                        switch (actionChoice)
                        {
                        case 1:
                            cout << "Add\n"; // AddNewClo(cloData, ploData, courseData); // must have PLO and course
                            break;
                        case 2:
                            cout << "Remove\n"; // RemoveCLO();
                            break;
                        case 3:
                            cout << "Update"; // UpdateCLO();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                        }
                    } while (actionChoice != 0);
                    break;
                case 5:
                    // cout << CLOTested(cloData) << endl;
                case 6:
                    // cout << CLOTested(courseData) << endl;
                case 7:
                /// CoursesInPlo(programData, ploData);
                case 0: // Exit
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (adminChoice != 0);
            break;
        case 2: // Teacher
            do
            {
                teacherChoice = TeacherMenu();
                switch (teacherChoice)
                {
                case 1: // AddCloTopic(cloData);
                    break;
                case 2: // Add Evaluation
                    do
                    {
                        evaluationChoice = EvaluationMenu();
                        switch (evaluationChoice)
                        {
                        case 1:
                            cout << "Quiz\n";
                            break;
                        case 2:
                            cout << "Exam\n";
                            break;
                        case 3:
                            cout << "Project\n";
                            break;
                        case 4:
                            cout << "Assignment\n";
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice, please try again.\n";
                        }
                    } while (evaluationChoice != 0);
                    break;
                case 3: // Associate CLO with evaluation
                    // Perform actions for associating CLO with evaluation
                    break;
                case 0: // Exit
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (teacherChoice != 0);
            break;
        case 0: // Exit
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (mainChoice != 0);

    return 0;
}