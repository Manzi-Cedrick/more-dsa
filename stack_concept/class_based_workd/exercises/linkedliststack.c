#include<iostream>
using namespace std;

template typename T;
class Node<T>{
public:
    T data;
    this->data = data;
    next = NULL;
};

class Stack{
    Node<T> *head;
    int size;
public:
    Stack(){
        head = NULL;
        size = 0;
    }
    void addElement(int el){
        Node<T> newNode = new Node(ele);
        newNode->next = head;
        newNode = head;
        size++;
    }
    void popElement(){
        if(isEmpty())
            cout << "Stack underflow";
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    T top(){
        if(isEmpty())
            cout << "Stack underflow";
        return head->data;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
};
int main () {
    Stack<int> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}
