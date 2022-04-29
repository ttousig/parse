#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"

//E1.Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”

/*E2.  Create a student object for each student in the data table and populate classRosterArray.

a.  Parse each set of data identified in the “studentData Table.”

b.  Add each student object to classRosterArray.
*/

const string studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Tesla,Tousignant,ttousig@wgu.edu,30,20,30,40,SOFTWARE" //A.  Modify the “studentData Table” to include your personal information as the last item.
};

int main()
{
    /* F 1.  Print out to the screen, via your application,
        the course title, the programming language used,
        your WGU student ID, and your name.*/
    cout << "C867 Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001438228" << endl;
    cout << "Name: Tesla Tousignant\n" << endl;

    // F 2.Instantiate Roster class, name: classRoster
    Roster classRoster;

    //variables needed for parsing, then used as parameters in add function
    string studentID = "";
    string firstName = "";
    string lastName = "";
    string emailAddress = "";
    string studentAge = "";
    int daysInCourse1 = 0;
    int daysInCourse2 = 0;
    int daysInCourse3 = 0;
    string degreeProgramTemp = "";
    DegreeProgram degreeProgram = DegreeProgram::NETWORK;

    //E2.a.  Parse each set of data identified in the “studentData Table.” ; Parse strings in studentData[]
    //Parse method based on video in Tip #10 --"Parsing a string on delimiter with String stream"
    for (int i = 0; i < 5; i++)
    {
        string currentLineString = studentData[i]; //takes  string element of studentData array, which is separated by comma outside of the "string"; grabs single row of datas
        vector<string> dataParts; //will split long string row of data 
        stringstream s_stream(currentLineString); //creates string stream from the long string
        while (s_stream.good())//parsing
        {
            string subString;
            getline(s_stream, subString, ','); //get string delimited by comma
            dataParts.push_back(subString); //puts each data between comma, in the end of the vector
        }
        string studentID = dataParts.at(0);
        string firstName = dataParts.at(1);
        string lastName = dataParts.at(2);
        string emailAddress = dataParts.at(3);
        string studentAge = dataParts.at(4);
        int daysInCourse1 = stoi(dataParts.at(5));
        int daysInCourse2 = stoi(dataParts.at(6));
        int daysInCourse3 = stoi(dataParts.at(7));
        string degreeProgramTemp = dataParts.at(8);

        if (degreeProgramTemp == "SECURITY")  
        {
             degreeProgram = DegreeProgram::SECURITY;
        }

        if (degreeProgramTemp == "NETWORK")
        {
             degreeProgram = DegreeProgram::NETWORK;
        }

        if (degreeProgramTemp == "SOFTWARE")
        {
             degreeProgram = DegreeProgram::SOFTWARE;
        }
        // F 3.  Add each student to classRoster.
        classRoster.add(studentID,
            firstName,
            lastName,
            emailAddress,
            studentAge,
            daysInCourse1,
            daysInCourse2,
            daysInCourse3,
            degreeProgram);
     }
 
    classRoster.printAll();

    classRoster.printInvalidEmails();
   
    for (int i = 0; i < 5; i++)
    {
       classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3"); //should JUST print a message saying such a student with this ID was not found.
    
  //release the memory that was allocated dynamically 
     for (int i = 0; i < 5; i++)
     {
         classRoster.classRosterArray[i] = nullptr;
     }
    return 0; // destructor automatically called at return 0
 }