#include <iostream>
using namespace std;

struct Queue
{
    int front, rear, n;
    int *queue, *arr;
    Queue(int c)
    {
        front = rear = -1;
        n = c;
        queue = new int[n];
    }
    void enqueue()
    {
        int val;
        if (rear == n - 1)
            cout << "Queue OverflowFull" << endl;
        else
        {
            if (front == -1)
                front = 0;
            cout << "Insert the element in the queue: " << endl;
            cin >> val;
            rear++;
            queue[rear] = val;
        }
    }
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow";
            return;
        }
        cout << "Element deleted from queue is: " << queue[front] << endl;
        front++;
    }
    void display()
    {
        if (front == -1)
            cout << "Queue is empty" << endl;
        else
        {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++)
                cout << queue[i] << "\t";
            cout << endl;
        }
    }
    void readFront()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << "Element at front is: " << queue[front] << endl;
    }
};

int main()
{
    Queue q(5);
    int ch;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element to queue" << endl;
    cout << "3) Display al the elements of queue" << endl;
    cout << "4) Read element from the queue" << endl;
    cout << "5) Exit" << endl;
    do
    {
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.readFront();
        case 5:
            cout << "Exited the Queue" << endl;
            break;
        default:
            cout << "Invalid operation" << endl;
        }
    } while (ch > 0 && ch < 5);
    return 0;
}