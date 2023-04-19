#include<iostream>
using namespace std ;

class Student 
{
    public:
        int id;
        string name;
        int age;
        Student *student;
    Student(int roll, string name,int age)
    {
        this->id = roll;
        this->age = age;
        this->name = name;
    }
}student;
int main () 
{
    Student s1 =  Student(1,"Javis",19);
    Student s2 =  Student(2,"Mugabo",23);
    Student s3 =  Student(3,"Maria",23);
    Student s4 =  Student(4,"Muhire",23);
    Student s4 =  Student(5,"Peter",23);
    

}