#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void inOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
        inOrderTraversal(node->left);
        cout << node->data << "->";
        inOrderTraversal(node->right);
    }
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(20);
}