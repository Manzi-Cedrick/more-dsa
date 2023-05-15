#include <iostream>
using namespace std;

class AdjacencyMatrix
{
private:
    int n;
    int **adj;

public:
    AdjacencyMatrix(int n)
    {
        this->n = n;
        adj = new int *[n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add_edge(int origin, int destination)
    {
        if (origin > n || destination > n || destination <= 0 || origin <= 0)
        {
            cout << "Invalid Edge declaration";
            return;
        }
        adj[origin - 1][destination - 1] = 1;
        adj[destination - 1][origin - 1] = 1;
    }
    void delete_edge(int origin, int destination)
    {
        if (origin > n || destination > n || origin <= 0 || destination <= 0)
        {
            cout << "Invalid edge!\n";
            return ;
        }
        adj[origin - 1][destination - 1] = 0;
    }
};

int main()
{
    int nodes, max_edges, edges, origin, destin;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of egdes: ";
    cin >> edges;
    if (edges > (nodes * nodes))
    {
        cout << "invalid number of edges" << endl;
        return 0;
    }
    AdjacencyMatrix am(nodes);
    for (int i = 0; i < edges; i++)
    {
        cout << "Edges number :" << i + 1 << endl;
        cout << "Enter edge (-1 -1 to exit): " << endl;
        cout << "Enter Origin and destination vertices :" << endl;
        cin >> origin >> destin;
        if (origin == -1 || destin == -1)
            break;
        am.add_edge(origin, destin);
    }
    am.display();
    am.delete_edge(1, 2);
    am.delete_edge(2, 2);
    cout << "After deleting two edges" << endl;
    am.display();
    return 0;
}
