#include <bits/stdc++.h>
// #include <iostream>
// #include <fstream>
// #include <string.h>
// #include <string>
using namespace std;
struct Student
{
    int rollNumber;
    string studentName;
    int studentAge;
    float studentMarks;
} s1, s2, s3;
Student students[] = {s1, s2, s3};
Student retrievedStudent;
vector<Student> retrivedStudents = {};
Student retrievedStudents[] = {};
void mergeSort(Student arr[], int left, int right)
{
    cout << "main"; 
    int m = 0;
    while(m < 3){
        cout << "marks for " << m <<  retrievedStudents[m].studentMarks << "\n";
    m++;
    }
    if (left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        int i, j, k;
        int n1 = middle - left + 1;
        int n2 = right - middle;
        Student L[n1], R[n2];
        for (i = 0; i < n1; i++)
        {
            L[i] = arr[left + i];
        }
        for (j = 0; j < n2; j++)
        {
            R[j] = arr[middle + 1 + j];
        }
        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2)
        {
            if (L[i].studentMarks <= R[j].studentMarks)
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}
void readStudents()
{
    fstream myFile;
    myFile.open("recordings.txt", ios::in);
    if (myFile.is_open())
    {
        string line;
        int i = 0;
        while (getline(myFile, line))
        {
            if (line == "")
            {
                continue;
            }
            else
            {
                int pos = line.find(",");
                int rollNumber = stoi(line.substr(0, pos));
                line = line.substr(pos + 2);
                pos = line.find(",");
                string name = line.substr(0, pos);
                line = line.substr(pos + 2);
                pos = line.find(",");
                int age = stoi(line.substr(0, pos));
                line = line.substr(pos + 2);
                pos = line.find(",");
                int marks = stoi(line.substr(0, pos));
                retrievedStudents[i].studentName = name;
                retrievedStudents[i].studentAge = age;
                retrievedStudents[i].studentMarks = marks;
                i++;
            }
        }
            mergeSort(retrievedStudents,0,4);
    }
}
void saveStudents()
{
    fstream myfile;
    myfile.open("recordings.txt", ios::in | ios::app);
    if (!myfile)
    {
        cout << "Error :  Enable to open file " << endl;
        return;
    }
    int i = 0;
    while (i < 3)
    {
        myfile << "" << endl;
        myfile << students[i].rollNumber << ", " << students[i].studentName << ", " << students[i].studentAge << ", " << students[i].studentMarks << endl;
        i++;
    }
    myfile.close();
    // readStudents();
}
void getInputs()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "For student  : " << i << endl;
        cout << "Enter the studentName : ";
        cin >> students[i].studentName;
    checkAge:
        cout << "Enter the studentAge : ";
        cin >> students[i].studentAge;
        if (students[i].studentAge < 10 || students[i].studentAge > 30)
        {
            cout << " student Age should be between 10 and 30 years old " << endl;
            goto checkAge;
        }
    main:
        cout << "ENter the studentMarks : ";
        cin >> students[i].studentMarks;
        if (students[i].studentMarks < 0 || students[i].studentMarks > 50)
        {
            cout << "Marks should not exceed 50 or go bellow 0" << endl;
            goto main;
        }
    }
    saveStudents();
}
class Validator
{
public:
    void validateName(string name)
    {
        if (name.size() < 5)
        {
            cout << "Please no student name shoul have length less than five" << endl;
            return;
        }
    }
    void validateAge(int age)
    {
        if (age == 0)
        {
            cout << " please no person with zero " << endl;
        }
    }
    void validateMarks(float marks)
    {
        if (marks == 0)
        {
            cout << "that student is fool" << endl;
        }
    }
};
int main()
{
    readStudents();
    // getInputs();

    return 0;
}