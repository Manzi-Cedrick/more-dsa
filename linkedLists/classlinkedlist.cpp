#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;

};
void display (Node *node) 
{
    while (node != NULL)
    {
        /* code */
        cout << node->data;
        node = node->next;
    }
    
}
Node *createNewNode (int data,Node *n2) 
{
    Node *newNd = new Node ();
    newNd->data = data;
    n2 = newNd->next;
    return newNd;
}
void shiftNode (Node *n1,Node *n2) 
{
    n1->next = n2;
    n1->next = n1;
}
int main () 
{
    Node *n1 = new Node ();
    Node *n2 = new Node ();
    Node *n3 = new Node ();
    n1->data = 10;
    // display(n1);
    // createNewNode(10,n2);
    cout << createNewNode(20,n1)->data;
}