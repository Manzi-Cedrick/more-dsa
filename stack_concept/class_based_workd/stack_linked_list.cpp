#include <iostream>
using namespace std;

class Stack {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
    };
    Node* head;
    int size;

public:
    Stack() {
        head = NULL;
        size = 0;
    }


    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        head = newNode;
        size++;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return head->data;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
};

int main() {
    Stack stack;
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
