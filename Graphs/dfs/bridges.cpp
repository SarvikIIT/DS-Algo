#include <bits/stdc++.h>
using namespace std;

#define N 100

bool vis[N];
vector<int> arr[N];
int in[N];
int lo[N];
int timer = 0;

vector<pair<int, int>> bridges;

void dfs(int root, int parent) {
    vis[root] = true;
    in[root] = lo[root] = timer++;

    for (auto child : arr[root]) {
        if (child == parent) continue;

        if (vis[child]) {
            lo[root] = min(lo[root], in[child]);
        } else {
            dfs(child, root);
            lo[root] = min(lo[root], lo[child]);
            //Bridge Condition:
            if (lo[child] > in[root]) {
                bridges.push_back({root, child});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }

    cout << "Bridges found: " << bridges.size() << "\n";
    for (auto &edge : bridges) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}
