#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int findParent(int u, vector<int> &parent) {
    if (parent[u] != u)
        parent[u] = findParent(parent[u], parent);
    return parent[u];
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v) {
        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[u] > rank[v]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int kruskal(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int totalWeight = 0;

    for (auto &e : edges) {
        int u = e.u, v = e.v, w = e.w;

        if (findParent(u, parent) != findParent(v, parent)) {
            totalWeight += w;
            unionSet(u, v, parent, rank);
        }
    }

    return totalWeight;
}

int main() {
    int V;
    cin >> V;

    vector<Edge> edges;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int w;
            cin >> w;
            if (w != 0 && i < j) {
                edges.push_back({i, j, w});
            }
        }
    }

    int result = kruskal(V, edges);

    cout << "Minimum Spanning Weight: " << result;

    return 0;
}
