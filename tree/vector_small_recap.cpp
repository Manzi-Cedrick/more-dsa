#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2[3] = 40;
    v2[4] = 50;
    v2.push_back(60);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }
    
}