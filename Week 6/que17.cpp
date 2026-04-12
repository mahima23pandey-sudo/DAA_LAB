#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> &adjM, vector<bool> &visited, vector<bool> &recStack, int node, int V) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adjM[node][i] != 0) {
            if (!visited[i]) {
                if (dfs(adjM, visited, recStack, i, V))
                    return true;
            }
            else if (recStack[i]) {
                return true; 
            }
        }
    }

    recStack[node] = false; 
    return false;
}

bool hasCycle(vector<vector<int>> &adjM, int V) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(adjM, visited, recStack, i, V))
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

    if (hasCycle(adjM, V))
        cout << "Yes Cycle Exists";
    else
        cout << "No Cycle Exists";

    return 0;
}
