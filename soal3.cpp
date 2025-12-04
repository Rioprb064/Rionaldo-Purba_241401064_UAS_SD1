#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

void dijkstra(int V, vector<vector<iPair>> &adj, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; i++){
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<iPair>> adj(V);

    adj[0].push_back({1, 70});
    adj[0].push_back({2, 60});
    adj[1].push_back({3, 50});
    adj[2].push_back({4, 90});
    adj[2].push_back({0, 80});
    adj[3].push_back({5, 45});
    adj[3].push_back({4, 65});
    adj[4].push_back({5, 120});

    dijkstra(V, adj, 0);
    return 0;
}