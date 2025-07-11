#include <bits/stdc++.h>
using namespace std;

#define N 100

struct edge {
    int a;
    int b;
    int w;
};

edge arr[N];
vector<int> parent(N);
vector<int> dsusize(N);

bool comp(edge a, edge b) {
    return a.w < b.w;
}

// DSU Functions
void make(int v) {
    parent[v] = v;
    dsusize[v] = 1;
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);  // Path compression
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (dsusize[a] < dsusize[b]) swap(a, b);
        parent[b] = a;
        dsusize[a] += dsusize[b];
    }
}

int main() {
    int ans = 0;
    int n, m;
    int a, b, w;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }

    for (int i = 1; i <= n; ++i) {
        make(i);
    }

    sort(arr, arr + m, comp);

    for (int i = 0; i < m; ++i) {
        a = find(arr[i].a);
        b = find(arr[i].b);
        if (a != b) {
            ans += arr[i].w;
            unite(a, b);
        }
    }

    cout << "The minimum Spanning Tree is for the cost: " << ans << endl;
    return 0;
}
