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
        if (origin > n || destination > n || destination <= 0 || origin <= 0)
        {
            cout << "Invalid edge declaration";
            return;
        }
        adj[origin - 1][destination - 1] = 0;
        adj[destination - 1][origin - 1] = 0;
    }
};

int main()
{
    int nodes, max_edges, origin, destination;
    cout << "Enter the no of nodes: ";
    cin >> nodes;
    AdjacencyMatrix am(nodes);
    max_edges = nodes * nodes;
    for (int i = 0; i < max_edges; i++)
    {
        cout << "Edges number" << i + 1 << endl;
        cout << "Enter the edges (-1 -1) to exit" << endl;
        cout << "Enter origin and destination vertices" << endl;
        cin >> origin >> destination;
        if (origin == -1 || destination == -1)
        {
            break;
        }
        am.add_edge(origin, destination);
    }
    am.display();
    return 0;
}
