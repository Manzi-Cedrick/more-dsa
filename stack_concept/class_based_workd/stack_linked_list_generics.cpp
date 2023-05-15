#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
    Node *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void push(T data)
    {
        Node *newNode = new Node(data);
        newNode->next = head; // connect new node to current head
        head = newNode;       // update head pointer to new node
        size++;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return head->data;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
};

int main()
{
    Stack<int> stack;
    Stack<char> stack_char;
    stack_char.push(90);
    cout << "Top element of char stack: " << stack_char.top() << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Size of stack: " << stack.getSize() << endl;
    cout << "Top element of stack: " << stack.top() << endl;
    stack.pop();
    cout << "Size of stack: " << stack.getSize() << endl;
    cout << "Top element of stack: " << stack.top() << endl;
    stack.pop();
    cout << "Size of stack: " << stack.getSize() << endl;
    cout << "Top element of stack: " << stack.top() << endl;
    return 0;
}
