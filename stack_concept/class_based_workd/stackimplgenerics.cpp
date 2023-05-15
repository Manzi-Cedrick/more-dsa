#include <iostream>
#include <stdexcept>
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
            this->next = nullptr;
        }
    };
    Node *head;
    int size;

public:
    Stack()
    {
        head = nullptr;
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
        newNode->next = head;
        head = newNode;
        size++;
    }

    T top()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack underflow");
        }
        return head->data;
    }

    void pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack underflow");
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
};
int main()
{
    Stack<int> s;
    Stack<string> names;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    names.push("Iris");
    names.push("Manzi");
    names.push("Derrick");
    cout << s.top() << endl;
    cout << names.top() << endl;
    return 0;
}