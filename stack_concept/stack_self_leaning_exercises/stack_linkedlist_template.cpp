#include <iostream>
using namespace std;

template <typename T>
class Node
{
    T Data;
    Node<T> next;

public:
    Node(T Data)
    {
        this->Data = Data;
        next = NULL;
    }
};
template <typename t>
class Stack
{
    Node<t> *head;
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
    void push(t n)
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return;
        }
        Node<t> *n = new Node<t>(n);
        n->next = head;
        size++
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return;
        }
        Node<t> *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    t top()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return;
        }
        return head->Data;
    }
    int getSize()
    {
        return size;
    }
};
int main()
{
    Stack<int> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}
