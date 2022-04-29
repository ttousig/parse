#pragma once
#include<string>
using namespace std;

/*Define an enumerated data type DegreeProgram for the degree programs 
containing the data type values SECURITY, NETWORK, and SOFTWARE.
Note: This information should be included in the degree.h file.*/

enum class DegreeProgram
{ 
	SECURITY, 
	NETWORK, 
	SOFTWARE
}; //has 3 possible values ; SECURITY = 0, NETWORK = 1, SOFTWARE = 2

//Parallel string array
static const string DegreeProgramStrings[] = 
{
  "SECURITY",
  "NETWORK",
  "SOFTWARE"
};  

//Code testing:
/*
int main()
{
    //step 1- create DegreeProgram, print values w/ string equivalents
    DegreeProgram degreeProgram = DegreeProgram::SECURITY;
    cout << "A degree program and its name: ";
    cout<<(int)degreeProgram << ' ' << DegreeProgramStrings[(int)degreeProgram] << endl;
    //print all enum values and string equivalents in loop
    cout <<"All degree programs and their names:" << endl;
    for(int i = 0; i < 4; i ++)
    {
        cout << i << ' ' << DegreeProgramStrings[i] << endl;
    }
    return 0;
} 
//**after testing, end of code says "Segmentation fault (sore dumped)**

*/