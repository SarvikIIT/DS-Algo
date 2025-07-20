#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9 + 7;

vector<int> ar;              // Input array
vector<int> segment_tree;    // Segment tree

void buildTree(int start_index, int end_index, int segment_index) {
    if (start_index == end_index) {
        segment_tree[segment_index] = ar[start_index];
        return;
    }

    int mid = (start_index + end_index) / 2;
    buildTree(start_index, mid, 2 * segment_index);
    buildTree(mid + 1, end_index, 2 * segment_index + 1);

    segment_tree[segment_index] = min(segment_tree[2 * segment_index], segment_tree[2 * segment_index + 1]);
}

int findQuery(int start_index, int end_index, int segment_index, int query_start, int query_end) {
    // No overlap
    if (query_end < start_index || query_start > end_index)
        return INF;

    // Total overlap
    if (query_start <= start_index && end_index <= query_end)
        return segment_tree[segment_index];

    // Partial overlap
    int mid = (start_index + end_index) / 2;
    int left = findQuery(start_index, mid, 2 * segment_index, query_start, query_end);
    int right = findQuery(mid + 1, end_index, 2 * segment_index + 1, query_start, query_end);

    return min(left, right);
}

int32_t main() {
    int n;
    cin >> n;

    ar.resize(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    segment_tree.resize(4 * n, INF); // Large Size for safety against sparse data:
    buildTree(0, n - 1, 1);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << findQuery(0, n - 1, 1, l, r) << endl;
    }

    return 0;
}
