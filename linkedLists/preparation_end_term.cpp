#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }  
};
Node *head = NULL;
void print(Node *head){
    while(head != NULL){
        cout << "head dat"<< head->data;
        head = head->next;
    }
}
Node* reverse(Node *head){
    Node *current = NULL;
    Node *previous = NULL;
    Node *n = NULL;
    while (current != NULL)
    {
        current->next = n;
        current->next = previous;
        previous= current;
        current=n;
    }
    return previous;
}
Node* addElement(Node *head,int element){
    Node *n= new Node(element);
    n->next = head;
    head = n;
    return head;
}
bool searching(Node *head,int x){
    Node *current = head;
    while(current!=NULL){
        if(current->data == x){
            return true;
        }
        current = current->next;
    }
    return false;
}
int searchIndex(Node *head,int x){
    int index = 1;
    Node *current = head;
    while(current!=NULL){
        if(current->data == x){
            return index;
        }
        current = current->next;
        index++;
    }
    return index;
}
Node *deleteFirstNode(Node *head){
    Node *temp = head;
    head = temp->next;
    delete temp;
    return head;
}
Node *deleteLastNode(Node *head){
    Node *second_last = head;
    while(second_last->next->next != NULL){
        second_last = second_last->next;
    }
    delete second_last;
    second_last->next = NULL;
    return head;
}