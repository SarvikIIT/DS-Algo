#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
const int N = 1000;

vector<pair<int, int>> ar[N + 1];

//Priority Queue initilization is done as : priority_queue<Type, Container, Comparator>

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<int> dist(N + 1, INF);

void Dijkstra(int root) {
    pq.push({0, root});
    dist[root] = 0;

    while (!pq.empty()) {
        int curr_d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (curr_d > dist[curr]) continue;

        for (auto child : ar[curr]) {
            int next = child.second;
            int weight = child.first;

            if (curr_d + weight < dist[next]) {
                dist[next] = curr_d + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, w;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        ar[a].push_back({w,b});
        ar[b].push_back({w,a});
    }

    Dijkstra(1); // Starting from node 1

    for (int i = 1; i <= n; ++i) {
        cout << "The minimum distance of node " << i << " from the source is: ";
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << "\n";
    }

    return 0;
}
