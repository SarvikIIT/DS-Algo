#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> arr[N];
vector<bool> vis(N, false);
vector<int> color(N, 0);

bool dfs(int root, int x) {
    vis[root] = true;
    color[root] = x;
    // cout << "Node now visited: " << root << endl;
    for (auto child : arr[root]) {
        if (vis[child]) {
            if (color[root] == color[child]) {
                cout << "Not Bipartite" << endl;
                return false;
            }
        } else {
            if (!dfs(child, x ^ 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int v1, v2;
    for (int i = 0; i < n; ++i) {
        cin >> v1 >> v2;
        arr[v1].push_back(v2);
        arr[v2].push_back(v1);
    }
    
    if (dfs(1, 0)) {
        cout << "Graph is Bipartite" << endl;
    }

    return 0;
}
