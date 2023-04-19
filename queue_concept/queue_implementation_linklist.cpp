#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
struct Queue
{
    Node *head;
    Node *tail;
    int size;
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    int getSize()
    {
        return size;
    }
    void enquero(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        size++;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    int front()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "temp data : " << temp->data << endl;
            temp = temp->next;
        }
    }
    int count () {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            /* code */
            count++;
        }
        return count;
    }
};
int main()
{
    Queue q;
    q.enquero(10);
    q.enquero(20);
    q.enquero(30);
    q.enquero(40);
    q.enquero(50);
    q.enquero(60);
    q.enquero(70);
    q.display(); // should output: temp data : 10temp data : 20temp data : 30
    cout << q.front() << endl;   // should output: 20
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;   // should output: 20
    cout << q.getSize() << endl; // should output: 2
    cout << q.isEmpty() << endl; // should output: 0
    q.enquero(60);
    q.enquero(70);
    q.display();
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;   // should output: 20
    cout << q.getSize() << endl; // should output: 2
    cout << "Lenght" << q.count() << endl;
    while (!q.isEmpty())
    {
        cout << q.front() << endl; 
        q.display();
        q.dequeue();
    }
    return 0;
}