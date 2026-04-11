#include <iostream>
#include <vector>
using namespace std;


bool dfs(vector<vector<int>> &adjM, vector<bool> &visited, int src, int dest, int V) {

    if (src == dest)
        return true;

    visited[src] = true;

    
    for (int i = 0; i < V; i++) {
        if (adjM[src][i] != 0 && !visited[i]) {
            if (dfs(adjM, visited, i, dest, V))
                return true;
        }
    }

    return false;
}

int main() {
    int V;
    cin >> V;


    vector<vector<int>> adjM(V, vector<int>(V));


    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adjM[i][j];
        }
    }

    int src, dest;
    cin >> src >> dest;

    vector<bool> visited(V, false);

    // Check path
    if (dfs(adjM, visited, src, dest, V))
        cout << "Yes Path Exists";
    else
        cout << "No Such Path Exists";

    return 0;
}
