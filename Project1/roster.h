#pragma once
#include "student.h"
#include<string>

class Roster
{
public:
   //Varaibles needs for member functions
    int Index = 0;
    static const int numStudents = 5;
    Student* classRosterArray[numStudents];
    
    bool foundStudent = false;

    //adds student object into array roster
    void add(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        string age, 
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeprogram);

    // Member functions of class
    void remove(string studentID); //remove student by using ID
    void printAll();//prints out all student objects
    void printAverageDaysInCourse(string studentID); //based on student ID
    void printInvalidEmails(); // prints out invalid student emails
    void printByDegreeProgram(DegreeProgram degreeProgram); //prints out all students with same degree program

    ~Roster(); //destructor for roster
};