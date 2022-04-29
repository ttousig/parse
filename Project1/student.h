#pragma once
#include<string>
#include "degree.h"

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

class Student
{
    private: //nothing can touch these except the object itself
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        string studentAge;
        int daysComplet[3]; ////size of array has to be made constant in C++
        DegreeProgram degreeProgram;

	public:
        Student(string studentID,  //Full parameter constructor; passes in all the attributes of student
        string firstName,
        string lastName,
        string emailAddress,
        string studentAge,
        int daysComplet[],
        DegreeProgram degreeProgram);

        //accessors (getters)
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        string getStudentAge();
        int* getDaysComplet();  //use pointer to int, equalivant other prog.lang. array access, numbers !!CANNOT be returned normally in arrays in C++
        DegreeProgram getDegreeProgram();

        //mutators (setters)
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setStudentAge(string studentAge);
        void setDaysComplet(int daysComplet[]);
        void setDegreeProgram(DegreeProgram degreeProgram);
        void print(); //displays 'this' individual student object's data

        ~Student(); //Destructor
};