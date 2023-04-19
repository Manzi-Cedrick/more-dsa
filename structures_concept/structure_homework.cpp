#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    string student_name;
    int age;
    int rollNumber;
    float marks;
};

void mergeArray(Student *s, int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    Student *L = new Student[n1];
    Student *R = new Student[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = s[start + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = s[mid + j + 1];
    }
    i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (L[i].marks >= R[j].marks)
        {
            s[k] = L[i];
            i++;
        }
        else
        {
            s[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        s[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        s[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortData(Student *s, int start, int end)
{
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSortData(s, start, mid);
        mergeSortData(s, mid + 1, end);
        mergeArray(s, start, mid, end); 
    }
}
void printStruct(Student *s, int n)
{
    mergeSortData(s, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << "========================================== RANKINGS ======================================" <<endl;
        cout << "Name: " << s[i].student_name << endl;
        cout << "Age: " << s[i].age << endl;
        cout << "Roll Number : " << s[i].rollNumber << endl;
    }
}
void insertStruct(Student *s, int n, string filename)
{
    fstream file;
    file.open(filename, ios::out);
    if (!file)
    {
        cout << "Error opening file" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        file << s[i].student_name << "," << s[i].age << "," << s[i].rollNumber << "," << s[i].age << endl;
    }
    file.close();
}
Student *readFromFileData(int n)
{
    int i = 0;
    Student *s = new Student[n];
    string line;
    fstream readFromFile("student.txt");
    if (readFromFile.is_open())
    {
        while (getline(readFromFile, line))
        {
            size_t pos = line.find(',');
            s[i].student_name = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(',');
            s[i].age = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find(',');
            s[i].rollNumber = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            s[i].marks = stof(line);
            i++;
        }
        readFromFile.close();
    }
    else
    {
        cout << "Unable to open file.";
    }
    return s;
}
void inputData(Student *s, int n)
{
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, s[i].student_name);
        cout << "Enter age: ";
        cin >> s[i].age;
        while (s[i].age <= 10 || s[i].age >= 20)
        {
            cout << "Bad creds -- Re-enter age:" << endl;
            cin >> s[i].age;
        }
        cout << "Enter roll number: ";
        cin >> s[i].rollNumber;
        while (s[i].rollNumber <= 0)
        {
            cout << "Bad creds -- Re-enter roll-number: " << endl;
            cin >> s[i].rollNumber;
        }

        cout << "Enter marks: ";
        cin >> s[i].marks;
        cout << "===============================================================================================" << endl;
    }
}
int main()
{
    int n;
    cout << "Insert the No of students: ";
    cin >> n;
    Student *s = new Student[n];
    inputData(s, n);
    insertStruct(s, n, "student.txt");
    Student *retrievedStudent = readFromFileData(n);
    printStruct(retrievedStudent, n);
    return 0;
}
