#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
};
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data:" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
}