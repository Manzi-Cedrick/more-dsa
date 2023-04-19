#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int nextIndex;
    int capacity;

public:
    Stack(int element)
    {
        capacity = element;
        nextIndex = 0;
        arr = new int[5];
    }
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack overflow";
        }
        else
        {
            int *newArray = new int[capacity*2];
            for (int i = 0; i < capacity; i++)
            {
                newArray[i] = arr[i];
            }
            delete []arr;
            arr=newArray;
            capacity=capacity*2;
            arr[nextIndex] = element;
            nextIndex++;
        }
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        bool check;
        nextIndex == 0 ? check = true : check = false;
        return check;
    }
    int top()
    {
        if(isEmpty()){
            cout << "Underflow integer" << endl;
            return 0;
        }
        return arr[nextIndex - 1];
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow " << endl;
        } else
        {
            nextIndex--;
        }
    }
};
int main()
{
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(50);
    s.push(60);
    s.push(80);
    s.push(800);
    cout << s.size() << endl;
    cout << s.top() << endl;
}
