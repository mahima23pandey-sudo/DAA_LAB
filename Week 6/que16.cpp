#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> &adjM, int V) {
    vector<int> color(V, -1); 
    
    for (int start = 0; start < V; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int i = 0; i < V; i++) {
                    if (adjM[node][i] != 0) {
                        if (color[i] == -1) {
                            color[i] = 1 - color[node];
                            q.push(i);
                        }
                        else if (color[i] == color[node]) {
                            return false; 
                        }
                    }
                }
            }
        }
    }
    return true;
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

    if (isBipartite(adjM, V))
        cout << "Yes Bipartite";
    else
        cout << "Not Bipartite";

    return 0;
}
