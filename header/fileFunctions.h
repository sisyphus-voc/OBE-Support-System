#include <iostream>
#include <vector>

using namespace std;

string InputAcademicOfficerFileName();
string InputTeacherFileName();
string InputProgramFileName();
string InputCourseFileName();
string InputPloFileName();
string InputCloFileName();

vector<vector<AcademicOfficer>> InputAcademicOfficerData(string);
vector<vector<Teacher>> InputTeacherData(string);
vector<vector<Program>> InputProgramData(string);
vector<vector<Course>> InputCourseData(string);
vector<vector<PLO>> InputPloData(string);
vector<vector<CLO>> InputCloData(string);
