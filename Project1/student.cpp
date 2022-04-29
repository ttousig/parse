#include <iostream>
#include "student.h"
#include<string>

/*
D.  For the Student class, do the following:

D1.  Create the class Student  in the files student.h and student.cpp,
which includes each of the following variables:
•  student ID
•  first name
•  last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program
*/

//Full constructor-initializes attrubutes of student object, passes paramter values to create particular student object
Student::Student(string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    string studentAge,
    int daysComplet[],
    DegreeProgram degreeProgram)
{
 //this Data member of object = parameter passed in
    this->studentID = studentID; 
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->studentAge = studentAge;
    for (int i = 0; i < 3; i++)
    {
        this->daysComplet[i] = daysComplet[i];
    }
    this->degreeProgram = degreeProgram;
}

//Getters
string Student::getStudentID() //{ return this->studentID; }
{
    return studentID;
}

string Student::getFirstName() //{ return this->firstName; }
{
    return firstName;
}

string Student::getLastName() //{ return this->lastName; }
{
    return lastName;
}

string Student::getEmailAddress() //{ return this->emailAddress; }
{
    return emailAddress;
}

string Student::getStudentAge() //{ return this->studentAge; }
{
    return studentAge;
}

int* Student::getDaysComplet()//returning an array by using pointer //{ return this->daysComplet; } 
{
    return daysComplet;
}

DegreeProgram Student::getDegreeProgram() //{ return this->degreeProgram; }
{
    return degreeProgram;
}

//Setters
void Student::setStudentID(string studentID)
{ 
    this->studentID = studentID; 
}

void Student::setFirstName(string firstName)
{ 
    this->firstName = firstName; 
}

void Student::setLastName(string lastName)
{ 
    this->lastName = lastName; 
}

void Student::setEmailAddress(string emailAddress)
{ 
    this->emailAddress = emailAddress; 
}

void Student::setStudentAge(string studentAge)
{ 
    this->studentAge = studentAge; 
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{ 
    this->degreeProgram = degreeProgram;
}

void Student::setDaysComplet(int daysComplet[]) //sets each int of days in index of daysComplet Array
{
    for (int i = 0; i < 3; i++)
    {
        this->daysComplet[i] = daysComplet[i];
    }
}

//**NEED TO USE /t 
//format format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20[tab]daysInCourse: {35, 40, 55} Degree Program: Security.
void Student::print() //outputs student object info
{
    cout << studentID << '\t';
    cout << "First Name: " << firstName << '\t';
    cout << "Last Name: " << lastName << '\t';
    cout << "Age: " << studentAge << '\t';
    int* daysComplet = getDaysComplet();
    cout << "daysInCourse: {" << *daysComplet << " " << *(daysComplet + 1) << " " << *(daysComplet + 2) << "}" << '\t';
    cout << "Degree Program: " << DegreeProgramStrings[(int)degreeProgram] << endl;
}

Student::~Student() {}//destructor 