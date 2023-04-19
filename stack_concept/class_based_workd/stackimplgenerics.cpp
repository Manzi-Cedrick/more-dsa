#include <iostream>
using namespace std;
template <typename T>

class Stack
{
private:
    T *arr;
    int nextIndex;
    int capacity;

public:
    Stack(int element)
    {
        capacity = element;
        nextIndex = 0;
        arr = new T[5];
    }
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack overflow";
        }
        else
        {
            T *newArray = new T[capacity*2];
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
    T top()
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
    Stack<int> s(10);
    Stack<char> cs(10);
    s.push(10);
    s.push(20);
    s.push(50);
    s.push(60);
    s.push(80);
    s.push(800);
    cs.push(96);
    cs.push(97);
    cs.push(98);
    cs.push(99);
    cs.push(100);
    cout << s.size() << endl;
    cout << cs.top() << endl;
}
