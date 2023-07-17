#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> v , int sv){
    int n = v.size();
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(sv);
    visited[sv];

    while (!q.empty()){
        int cv = q.front();
        q.pop();
        cout<<cv<<endl;
        for (int i = 0; i < n; ++i) {
            if(v[sv][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }

}

int main(){
    cout<<"Enter the number of Nodes and Edges"<<endl;
    int n,e;
    cin>>n>>e;
    vector<vector<int> > matrix(n , vector<int>(n,0));
    cout<<"Enter the Edges:"<<endl;
    for (int i = 1; i < e; ++i) {
        int fv , sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    cout<<"BFS"<<endl;
    bfs(matrix , 5);
    return 0;
}