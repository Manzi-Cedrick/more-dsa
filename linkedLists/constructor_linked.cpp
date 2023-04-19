#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;
        Node(int x)
        {
            this->data = x;
            this->next = NULL;
        }

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
int length (Node *node) 
{
    int n =0 ;

    while (node != NULL)
    {
        /* code */
        n++;
        node = node->next;
    }
    return n;
    
}
int main () 
{
    /// static initialization 
    Node n1(5);
    Node n2 = Node(10);
    n1.next = &n2;
    /// Dynamic initialization 
    Node *n3 = new Node(20);
    n2.next = n3;
    Node *head = &n1;
    display(head);
    int len = length(&n1);
    cout << "The length " << len;
    return 0;
}