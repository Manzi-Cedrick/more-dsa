#include <iostream>
using namespace std;

int stack[100], top = -1, n = 100;
// We initialize a stack with a value of -1 at the top.
int isFull()
{
    if (top == n - 1) // checks if the top index is equal to the last index of the stack
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (top <= -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int val)
{
    string message = "Stack overflow";
    if (isFull() == 1)
    {
        cout << message << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
void pop()
{
    string message = "Stack underflow";
    if (isEmpty() == 1)
    {
        cout << message << endl;
        return;
    }
    else
    {
        cout << "The following element is removed: " << stack[top] << endl;
        top--;
    }
}
int peek()
{
    if (top < 0)
    {
        cout << "Stack is empty ";
        return -1;
    }
    else
    {
        cout << "The top element : " << stack[top] << endl;
        return stack[top];
    }
}
int main()
{
}