#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    vector<int> scores;
    int id;
    string name;
    string grade;
    string className;

public:
    Student(int id, const string &name, const string &className)
    {
        this->id = id;
        this->name = name;
        this->className = className;
    }

    void setScores(const vector<int> &scores)
    {
        this->scores = scores;
    }

    void displayScores()
    {
        for (int i = 0; i < scores.size(); i++)
        {
            cout << scores[i] << " ";
        }
        cout << endl;
    }

    void displayStudent()
    {
        cout << "ID: " << this->id << endl;
        cout << "Name: " << this->name << endl;
        cout << "Class Name: " << this->className << endl;
        cout << "Grade: " << this->grade << endl;
        cout << "Scores: ";
        displayScores();
    }

    void setGrade()
    {
        if (scores.empty())
        {
            grade = "N/A";
            return;
        }

        double sum = 0.0;
        for (int i=0; i < scores.size(); i++)
        {
            sum += scores[i];
        }
        double average = sum / scores.size();

        if (average >= 90)
            grade = "A";
        else if (average >= 80)
            grade = "B";
        else if (average >= 70)
            grade = "C";
        else if (average >= 60)
            grade = "D";
        else
            grade = "F";

    }
};

int main()
{
    cout << "==== WELCOME TO GRADING SYSTEM ======" << endl;

    int id;
    string name;
    string className;
    vector<int> scores(5);

    cout << "Enter the student ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter the student name: ";
    getline(cin, name);

    cout << "Enter the class: ";
    getline(cin, className);

    cout << "Enter the 5 scores respectively (Math, Physics, Embeded Systems, Java, DSA): ";
    for (size_t i = 0; i < scores.size(); i++)
    {
        cin >> scores[i];
    }

    Student student(id, name, className);
    student.setScores(scores);
    student.setGrade();

    cout << "Student Report: " << endl;
    student.displayStudent();

    return 0;
}