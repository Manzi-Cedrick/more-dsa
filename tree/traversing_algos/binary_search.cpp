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
        inOrderTraversal(node->left);
        cout << node->data << "->";
        inOrderTraversal(node->right);
    }
}
Node *searchNode(Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (root->data < key)
    {
        return searchNode(root->right, key);
    }
    return searchNode(root->left, key);
}
Node *createNode(int)
Node *insert(Node *node, int key)
{
    if (node == NULL || node->data == key)
    {
        return createNode(key);
    }
    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }
    return node;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(20);
}