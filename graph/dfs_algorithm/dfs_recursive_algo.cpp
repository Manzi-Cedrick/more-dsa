#include <iostream>
#include <vector>
using namespace std;

void printDFS(vector<vector<int>> v, int sv, vector<bool> &visited)
{
    visited[sv] = true;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[sv][i] == 1 && visited[i] == false)
        {
            visited[i] = true;
            printDFS(v, i, visited);
        }
    }
}
int main()
{
    int n, e;
    cout << "Enter the vertices number:" << endl;
    cin >> n;
    cout << "Enter the edges number: " << endl;
    cin >> e;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 1; i <= e; i++)
    {
        int fv, sv;
        cout << "Final vertex:" << endl;
        cin >> fv;
        cout << "Start vertex" << endl;
        cin >> sv;
        matrix[sv][fv] = 1;
        matrix[fv][sv] = 1;
    }
    vector<bool> visited(n, false);
}