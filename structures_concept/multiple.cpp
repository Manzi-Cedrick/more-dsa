#include <iostream>
using namespace std;
class Student
{
public:
    int id;
    int age;
    string name;
    Student *next;
    Student(int id, int age, string name)
    {
        this->id = id;
        this->age = age;
        this->name = name;
        next = NULL;
    }
};
Student *head = NULL;
// Here changes to head are reflected outside the function.
void addFirst(Student **head, int id,int age,string name)
{
    // create a new node
    Student *newStudent = new Student(id, age, name);
    newStudent->next = *head;
    *head = newStudent;
}
void display(Student *n)
{
    while (n != NULL)
    {
        cout << n->id << " " << n->name << " " << n->age << endl;
        n = n->next;
    }
}
int main()
{
    /// Statically
    Student n1(1, 20, "John");
    Student n2(2, 16, "Michaella");
    // To create a linked list n1.next should be the address of n2
    n1.next = &n2;
    // Head is not a node but a pointer to the first node
    Student *head = &n1;
    // Dynamically
    Student *n3 = new Student(3, 17, "Peter");
    Student *n4 = new Student(4, 18, "Maureen");
    // COnnect the second node and the third node
    n2.next = n3;
    // Link the third node and the fourth node
    n3->next = n4;
    addFirst(&head,7,8,"Moni");
    display(head);
    return 0;
}