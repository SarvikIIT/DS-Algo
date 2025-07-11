#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> arr[N];
vector<bool> vis(N, false);
bool CycleFound = false;
void dfs(int root, int parent) {
    if(CycleFound)return;
    vis[root] = true;
    for (auto child : arr[root]) {
        if (vis[child] && child != parent) {
            CycleFound=true;
            return;
        }
        if (!vis[child]) {
            dfs(child, root);
        }
    }
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

    dfs(1, -1);
    if(CycleFound)cout<<"Cycle Found!"<<endl;
    else cout<<"No Cycle Found!"<<endl;

    return 0;
}
