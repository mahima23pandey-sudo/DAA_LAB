#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

void printPath(vector<int> &parent, int j) {
    if (j == -1) return;
    printPath(parent, parent[j]);
    cout << j + 1;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> mat(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < V; j++) {
            mat[i][j] = s[j] - '0';
        }
    }

    int src;
    cin >> src;
    src--;

    vector<Edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (mat[i][j] != 0) {
                edges.push_back({i, j, mat[i][j]});
            }
        }
    }

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (i == src) {
            cout << src + 1 << ":" << 0 << endl;
        } else {
            printPath(parent, i);
            cout << ":" << dist[i] << endl;
        }
    }

    return 0;
}
