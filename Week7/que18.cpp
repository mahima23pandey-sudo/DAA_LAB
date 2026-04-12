#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void printPath(vector<int> &parent, int j) {
    if (j == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}

void dijkstra(vector<vector<int>> &graph, int V, int src) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    
    cout << "Vertex\tDistance\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int source; 
    cin >> source;

    dijkstra(graph, V, source);

    return 0;
}
