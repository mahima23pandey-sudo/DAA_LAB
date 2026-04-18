#include <bits/stdc++.h>
using namespace std;

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < V; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    int src, dest, k;
    cin >> src >> dest;
    cin >> k;

    src--; 
    dest--;

    const int INF = 1e9;

    vector<vector<int>> dp(k + 1, vector<int>(V, INF));
    dp[0][src] = 0;

    for (int e = 1; e <= k; e++) {
        for (int u = 0; u < V; u++) {
            if (dp[e - 1][u] != INF) {
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] != 0) {
                        dp[e][v] = min(dp[e][v], dp[e - 1][u] + graph[u][v]);
                    }
                }
            }
        }
    }

    if (dp[k][dest] == INF) {
        cout << "no path of length k is available";
    } else {
        cout << "Weight of shortest path from (" << src + 1 << "," << dest + 1 << ") with " << k << " edges : " << dp[k][dest];
    }

    return 0;
}
