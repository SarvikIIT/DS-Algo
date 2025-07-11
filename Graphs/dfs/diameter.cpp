//Consider Proof from CLRS or Mathematics Book or Reema Thareja

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> adj[N];
vector<bool> visited(N);
vector<int> height(N);

int farthest_node;
int max_height;
void dfs(int node, int h) {
    visited[node] = true;
    height[node] = h;

    if (h > max_height) {
        max_height = h;
        farthest_node = node;
    }

    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child, h + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    fill(visited.begin(), visited.end(), false);
    fill(height.begin(), height.end(), 0);
    max_height = 0;

    dfs(farthest_node, 0);

    cout << "Diameter of the tree is: " << max_height << endl;
    cout << "One end of diameter: " << farthest_node << endl;

    return 0;
}
