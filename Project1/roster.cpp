#include <iostream>
#include <string>
#include "roster.h"

//E.Create a Roster class (roster.cpp) by doing the following :
//E1.Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
/*E2.  Create a student object for each student in the data table and populate classRosterArray.

a.  Parse each set of data identified in the “studentData Table.”

b.  Add each student object to classRosterArray.
*/

void Roster::add(string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    string studentAge,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgram degreeProgram)
{
    //constructor will accept an array, not 3 indiviual ints
    int daysComplet[numStudents];
    daysComplet[0] = daysInCourse1;
    daysComplet[1] = daysInCourse2;
    daysComplet[2] = daysInCourse3;

    /*E2. b.  Add each student object to classRosterArray.*/
    // index of classRosterArray starts at 0, and increments by 1 w/ ++ after student object is added
    classRosterArray[Index++] = new Student(studentID, firstName, lastName, emailAddress, studentAge, daysComplet, degreeProgram);
}

/* removes students from the roster by student ID.
    If the student ID does not exist, the function prints
    an error message indicating that the student was not found.*/
void Roster::remove(string studentID)
{
    for (int i = 0; i < Roster::Index; i++) //Roster::Index is equal to the array size of classRosterArray
    {
        if (classRosterArray[i]->getStudentID() == studentID) //check for matching studentID
        {
            foundStudent = true;
            if (foundStudent)
            {
                cout << "Removing " << studentID << ":\n" << endl;
                Student* tempPlace = classRosterArray[i]; ////set up temp student to switch, will be moved the end of array
                classRosterArray[i] = classRosterArray[numStudents-1]; //goto last student and switch it with wanted removed student's index place
                classRosterArray[numStudents-1] = tempPlace;
                tempPlace = classRosterArray[i]; //student A5
                classRosterArray[i] = classRosterArray[i + 1];
                classRosterArray[i + 1] = tempPlace;
                delete classRosterArray[numStudents-1]; //delete found student with matching ID, which was moved to end of array
                Roster::Index--; //will appear to shrink array, and will be used in printAll function to make unwanted index to "disappear"
            }
        }
    }

    if (foundStudent == false)
    {
        cout << "Removing " << studentID << " again\n" << endl;
        cout << "The student with the ID: " << studentID << " was not found.\n" << endl;
    }
    foundStudent = false; //reset variable to original value
}

/* prints list of student data.
    The printAll() function should loop through all the students in
    classRosterArray and call the print() function for each student.*/
void Roster::printAll() 
{
    for (int i = 0; i < Roster::Index; i++) //need to get each student to use its function to display itself; RosterIndex will change size with the remove function
    {
        classRosterArray[i]->print(); //calls print function for each student object within roster
    }
    cout << "\n";
}
    
/* that correctly prints a student’s average number of days in
the three courses. The student is identified by the studentID parameter. -> use parameter string studentID to
located correct avg days in courses, then find average, output student ID with average calculated*/
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << "Student ID: " << studentID << ", averages " << ((int)classRosterArray[i] ->getDaysComplet()[0] + (int)classRosterArray[i]->getDaysComplet()[1] + (int)classRosterArray[i]->getDaysComplet()[2] ) / 3 << " days in a course" << endl;
        }
    }
}
    
/*that verifies student email addresses and displays all invalid email addresses to the user.
  Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').*/
void Roster::printInvalidEmails()
{
    cout << "Displaying invalid emails:\n" << endl;
    for (int i = 0; i < 5; i++)
    {
        string currentEmailToCheck = classRosterArray[i]->getEmailAddress();
        string emailInvalidIssue = "default";
        
        if (currentEmailToCheck.find(' ') != string::npos) // if space found, would equal string::npos
        {
            emailInvalidIssue = " - no spaces allowed";
            cout << currentEmailToCheck << emailInvalidIssue << endl;
        }

        if (currentEmailToCheck.find('.') == string::npos) // if missing a period, will equal string::npos
        {
            emailInvalidIssue = " - missing a period";
            cout << currentEmailToCheck << emailInvalidIssue << endl;
        }

        if (currentEmailToCheck.find('@') == string::npos) //if missing an @ symbol, will equal string::npos
        {
            emailInvalidIssue = " - missing an @ symbol";
            cout << currentEmailToCheck << emailInvalidIssue << endl;
        }
    }
    cout << "\n";
}

/* prints out student information for a degree program specified
 by an enumerated type.*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
   cout << "\nShowing students in degree program: " << DegreeProgramStrings[(int)degreeProgram] << "\n" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->print();
        }
    }
    cout << "\n";
}
Roster::~Roster() {} //destructor for roster