#include <iostream>
#include <string>
#include "header/menus.h"

using namespace std;

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
                            cout << "Add\n"; // AddProgram();
                            //prompt the user to enter the details about the program
                            //use those details to create and object and push it into the
                            //program data vector, then append it into the main file.
                            break;
                        case 2:
                            cout << "Remove\n"; // RemoveProgram();
                            //get the programCode from the user, go to the program data vector, delete the said vector and then replace the file data with the new updated vector.
                            break;
                        case 3:
                            cout << "Update"; // UpdateProgram();
                            //get program code of the vector that needs to be updated, make a copy of that vector and get info that needs to be changed, change it in the copy and swap the vectors in the main vector file and append
                            
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
                            cout << "Add\n"; // AddCourse();
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
                            cout << "Add\n"; // AddPLO();
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
                            cout << "Add\n"; // AddCLO();
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
                case 1: // Add CLO Topic
                    // Perform actions for adding CLO topic
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