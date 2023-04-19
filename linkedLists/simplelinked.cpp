#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
void display (Node *node){
    while(node != NULL){
        cout << node->data << endl;
        cout << "Node Address: " << node->next <<endl;
        node =  node->next ;
    }
}
int main () {
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    first->data = 10;
    first->next = second;
    second->data = 12;
    second->next = third;
    third->data = 20;
    // third->next = NULL;
    display(second);
}