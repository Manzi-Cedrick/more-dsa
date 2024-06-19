#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

class Courses
{
private:
    int courseId;
    string courseName;
    int marks;

public:
    Courses(int courseId, string courseName) : courseId(courseId), courseName(courseName), marks(0) {}
    int getCourseId() { return courseId; }
    string getCourseName() { return courseName; }
    void setMarks(int m) { marks = m; }
    int getMarks() { return marks; }
};

class Student
{
private:
    int studentRollNumber;
    string studentName;
    vector<Courses> courses;

public:
    Student(int roll, string studentName) : studentRollNumber(roll), studentName(studentName) {}

    int getRollNumber() { return studentRollNumber; }
    string getStudentName() { return studentName; }
    void addCourse(Courses course)
    {
        courses.push_back(course);
    }
    vector<Courses> &getCourses() { return courses; }
};

class LinkedList
{
private:
    struct Node
    {
        Student student;
        Node *next;
        Node(Student s) : student(s), next(nullptr) {}
    };

    Node *head;
    unordered_map<int, string> availableCourses;

public:
    LinkedList() : head(nullptr)
    {
        // Example available courses
        availableCourses[101] = "Math";
        availableCourses[102] = "Physics";
        availableCourses[103] = "Chemistry";
    }

    void addStudent(Student student)
    {
        Node *newNode = new Node(student);
        newNode->next = head;
        head = newNode;
    }

    void displayStudents()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << "Roll Number: " << current->student.getRollNumber() << endl;
            cout << "Student Name: " << current->student.getStudentName() << endl;
            cout << "Courses: " << endl;
            for (auto& course: current->student.getCourses())
            {
                cout << course.getCourseName() << " - Marks: " << course.getMarks() << endl;
            }
            cout << "---------------------" << endl;
            current = current->next;
        }
    }

    bool isCourseAvailable(int courseId)
    {
        return availableCourses.find(courseId) != availableCourses.end();
    }

    void showCourses()
    {
        cout << "Available Courses" << endl;
        cout << "---------------------" << endl;
        for (auto& course: availableCourses)
        {
            cout << course.first << " " << course.second << endl;
        }
        cout << "---------------------" << endl;
    }

    void enrollStudentToCourse(string studentName, int courseId, int marks)
    {
        if (!isCourseAvailable(courseId))
        {
            cout << "Course not available!" << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            if (current->student.getStudentName() == studentName)
            {
                Courses course(courseId, availableCourses[courseId]);
                course.setMarks(marks);
                current->student.addCourse(course);
                return;
            }
            current = current->next;
        }
        cout << "Student not found!" << endl;
    }

    void searchStudent(string studentName)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->student.getStudentName() == studentName)
            {
                cout << "Roll Number: " << current->student.getRollNumber() << endl;
                cout << "Student Name: " << current->student.getStudentName() << endl;
                cout << "Courses: " << endl;
                for (auto& course: current->student.getCourses())
                {
                    cout << course.getCourseName() << " - Marks: " << course.getMarks() << endl;
                }
                return;
            }
            current = current->next;
        }
        cout << "Student not found!" << endl;
    }

    void storeInformation()
    {
        ofstream file("students.csv");
        Node *current = head;
        while (current != nullptr)
        {
            file << current->student.getRollNumber() << "," << current->student.getStudentName() << endl;
            for (auto& course: current->student.getCourses())
            {
                file << course.getCourseId() << "," << course.getCourseName() << "," << course.getMarks() << endl;
            }
            file << endl;
            current = current->next;
        }
        file.close();
    }

    void loadInformation()
    {
        ifstream file("students.csv");
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;
            stringstream ss(line);
            string roll, name;
            getline(ss, roll, ',');
            getline(ss, name, ',');
            Student student(stoi(roll), name);
            addStudent(student);
            while (getline(file, line) && !line.empty())
            {
                stringstream ssCourse(line);
                string courseId, courseName, marks;
                getline(ssCourse, courseId, ',');
                getline(ssCourse, courseName, ',');
                getline(ssCourse, marks, ',');
                enrollStudentToCourse(name, stoi(courseId), stoi(marks));
            }
        }
        file.close();
    }
};

int main()
{
    LinkedList studentList;
    string command;

    cout << "Welcome to the Student Management System! Enter a command:" << endl;

    while (true)
    {
        cout << "> ";
        getline(cin, command);

        if (command == "create")
        {
            int roll;
            string studentName;
            cout << "Enter student roll number: ";
            cin >> roll;
            cin.ignore(); // Clear the input buffer
            cout << "Enter student name: ";
            getline(cin, studentName);
            studentList.addStudent(Student(roll, studentName));
            cout << "Student added successfully! 🚀" << endl;
        }
        else if (command == "enroll")
        {
            string studentName;
            int courseId, marks;
            cout << "Enter student name: ";
            getline(cin, studentName);
            cout << "Enter course id: ";
            cin >> courseId;
            cout << "Enter marks: ";
            cin >> marks;
            cin.ignore(); // Clear the input buffer
            studentList.enrollStudentToCourse(studentName, courseId, marks);
        }
        else if (command == "show-courses")
        {
            studentList.showCourses();
        }
        else if (command == "list")
        {
            studentList.displayStudents();
        }
        else if (command == "load")
        {
            studentList.loadInformation();
            cout << "Information loaded successfully!" << endl;
        }
        else if (command == "search")
        {
            string studentName;
            cout << "Enter student name: ";
            getline(cin, studentName);
            studentList.searchStudent(studentName);
        }
        else if (command == "save")
        {
            studentList.storeInformation();
            cout << "Information saved successfully!" << endl;
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}