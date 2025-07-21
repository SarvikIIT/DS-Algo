#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>

const int INF = 1e9 + 7;

vi data;
vi segtree;

void buildTree(int start_index, int end_index, int segment_index) {
    if (start_index == end_index) {
        segtree[segment_index] = data[start_index];
        return;
    }

    int mid = (start_index + end_index) / 2;
    buildTree(start_index, mid, 2 * segment_index + 1);
    buildTree(mid + 1, end_index, 2 * segment_index + 2);

    segtree[segment_index] = min(segtree[2 * segment_index + 1], segtree[2 * segment_index + 2]);
}

int findQuery(int q_start, int q_end, int start_index, int end_index, int segment_index) {
    // No overlap
    if (q_end < start_index || q_start > end_index)
        return INF;

    // Complete overlap
    if (q_start <= start_index && end_index <= q_end)
        return segtree[segment_index];

    // Partial overlap
    int mid = (start_index + end_index) / 2;
    int left = findQuery(q_start, q_end, start_index, mid, 2 * segment_index + 1);
    int right = findQuery(q_start, q_end, mid + 1, end_index, 2 * segment_index + 2);

    return min(left, right);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    data.resize(n);
    segtree.resize(4 * n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    buildTree(0, n - 1, 0);

    int q;
    cin >> q;

    while (q--) {
        int i, j;
        cin >> i >> j;
        int l = min(i, j);
        int r = max(i, j);
        cout << findQuery(l, r, 0, n - 1, 0) << '\n';
    }

    return 0;
}
