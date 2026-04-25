#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<pair<int,int>>> &adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    pq.push({0, 0});
    key[0] = 0;

    int totalCost = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalCost += weight;

        for (auto &it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    return totalCost;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << primMST(V, adj);

    return 0;
}
