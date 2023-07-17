#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void printTreeNode(Node<int> *root)
{
    cout << root->data << ": ";
    if (root == NULL)
    {
        cout << "No value";
        return;
    }
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data << " ";
    }
    printTreeNode(root->left);
    printTreeNode(root->right);
}
Node<int> *getInputLevelwise()
{
    int rootData;
    cout << "Enter the data: ";
    cin >> rootData;
    Node<int>* root = new Node<int>(rootData);
    queue<Node<int>*> q;
    q.push(root);
    while (!q.empty())
    {
        Node<int> *f = q.front();
        q.pop();
        cout << "Enter the left child of: " << f->data << ": ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            Node<int> *child = new Node<int>(leftChildData);
            q.push(child);
            f->left = child;
        }
        cout << "Enter the right child of: " << f->data << ": ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            Node<int> *child = new Node<int>(rightChildData);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}
int main()
{
    Node<int> *root = new Node<int>(1);
    Node<int> *n1 = new Node<int>(2);
    Node<int> *n2 = new Node<int>(3);
    root->left = n1;
    root->right = n2;
    Node<int> *n3 = new Node<int>(4);
    n1->left = n3;
    Node<int> *n4 = new Node<int>(5);
    n1->right = n4;
    printTreeNode(root);
    Node<int> *root2 = getInputLevelwise();
    printTreeNode(root2);
    delete root;
    return 0;
}