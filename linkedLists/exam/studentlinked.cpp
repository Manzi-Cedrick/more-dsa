#include <iostream>
#include <fstream>
#include <cstdio>
#include <sstream>

using namespace std;

class Student
{
public:
    int roll_number;
    string name;
    int age;
    float marks;
    Student *next;
    Student(int roll_number, string name, int age, int marks)
    {
        this->roll_number = roll_number;
        this->name = name;
        this->age = age;
        this->marks = marks;
    }
};
Student *UserData()
{
    int roll;
    string name;
    int age;
    float marks;
    Student *head = NULL;
    Student *tail = NULL;
    for (int i = 0; i < 2; i++)
    {
        cout << "Id: ";
        cin >> roll;
        while (roll < 0)
        {
            cout << "Bad creds -- Re-enter roll-number: ";
            cin >> roll;
        }
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        while (age < 10 || age > 30)
        {
            cout << "Bad creds -- Re-enter age:";
            cin >> age;
        }
        cout << "Marks: ";
        cin >> marks;
        while (marks < 0 || marks > 50)
        {
            cout << "Bad creds -- Re-enter marks:";
            cin >> marks;
        }
        Student *s = new Student(roll, name, age, marks);
        if (head == NULL)
        {
            head = s;
            tail = s;
        }
        else
        {
            tail->next = s;
            tail = s;
        }
    }
    return head;
}
void display(Student *s)
{
    int sum = 0, count = 0, avgMark = 0;
    if (s != NULL)
    {
        while (count < 5 && s != NULL)
        {
            count++;
            cout << s->roll_number << " , " << s->name << " , " << s->age << " , " << s->marks << endl;
            sum += s->marks;
            s = s->next;
            avgMark = (sum) / count;
            cout << endl << "The Average Mark: " << avgMark << " for: "<<count<<" record." << endl;
        }
        if (count > 0)
        {
            avgMark = (sum) / count;
            cout << "The Average Mark: " << avgMark;
        }
        else
        {
            cout << "No data found!" << endl;
        }
    }
}

void saveToCsv(string filename, Student *s)
{
    ofstream file(filename);
    if (file.is_open())
    {
        while (s != NULL)
        {
            file << s->roll_number << "," << s->name << "," << s->age << "," << s->marks << endl;
            s = s->next;
        }
        file.close();
        cout << "Successfully saved into the file: " << filename << endl;
    }
    else
    {
        cout << "Unable to open file!";
    }
}
Student *readFromCsv(string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        Student *head = NULL;
        Student *tail = NULL;
        string line;
        while (getline(file, line))
        {
            int roll_number;
            string name;
            int age;
            float marks;
            stringstream ss(line);
            string cell;
            if (getline(ss, cell, ','))
                roll_number = stoi(cell);
            if (getline(ss, cell, ','))
                name = cell;
            if (getline(ss, cell, ','))
                age = stoi(cell);
            if (getline(ss, cell, ','))
                marks = stof(cell);
            Student *s = new Student(roll_number, name, age, marks);
            if (head == NULL)
            {
                head = s;
                tail = s;
            }
            else
            {
                tail->next = s;
                tail = s;
            }
        }
        file.close();
        cout << "Successful retrieval" << filename << endl;
        return head;
    }
    else
    {
        cout << "Unable to open file!" << endl;
        return NULL;
    }
}
int main()
{
    Student *head = UserData();
    saveToCsv("student.csv", head);
    Student *root = readFromCsv("student.csv");
     if (root == NULL) {
        cout << "No data found!" << endl;
    } else {
        display(root);
    }
}