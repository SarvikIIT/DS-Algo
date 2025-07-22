#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e15;

vector<int> ar;              // Input Array
vector<int> segment_tree;    // Segment Tree
vector<int> LazyTree;        // Lazy Propagation Tree

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
    if (LazyTree[segment_index] != 0) {
        segment_tree[segment_index] += LazyTree[segment_index];
        if (start_index != end_index) {
            LazyTree[2 * segment_index] += LazyTree[segment_index];
            LazyTree[2 * segment_index + 1] += LazyTree[segment_index];
        }
        LazyTree[segment_index] = 0;
    }

    if (query_end < start_index || query_start > end_index)
        return INF;

    if (query_start <= start_index && end_index <= query_end)
        return segment_tree[segment_index];

    int mid = (start_index + end_index) / 2;
    int left = findQuery(start_index, mid, 2 * segment_index, query_start, query_end);
    int right = findQuery(mid + 1, end_index, 2 * segment_index + 1, query_start, query_end);

    return min(left, right);
}

void PointUpdate(int start_index, int end_index, int segment_index, int update_index, int new_value) {
    if (LazyTree[segment_index] != 0) {
        segment_tree[segment_index] += LazyTree[segment_index];
        if (start_index != end_index) {
            LazyTree[2 * segment_index] += LazyTree[segment_index];
            LazyTree[2 * segment_index + 1] += LazyTree[segment_index];
        }
        LazyTree[segment_index] = 0;
    }

    if (start_index == end_index) {
        segment_tree[segment_index] = new_value;
        ar[update_index] = new_value;
        return;
    }

    int mid = (start_index + end_index) / 2;
    if (update_index <= mid)
        PointUpdate(start_index, mid, 2 * segment_index, update_index, new_value);
    else
        PointUpdate(mid + 1, end_index, 2 * segment_index + 1, update_index, new_value);

    segment_tree[segment_index] = min(segment_tree[2 * segment_index], segment_tree[2 * segment_index + 1]);
}

void RangeUpdate(int start_index, int end_index, int segment_index, int update_start,int update_end, int change){
    if (LazyTree[segment_index] != 0) {
        segment_tree[segment_index] += LazyTree[segment_index];
        if (start_index != end_index) {
            LazyTree[2 * segment_index] += LazyTree[segment_index];
            LazyTree[2 * segment_index + 1] += LazyTree[segment_index];
        }
        LazyTree[segment_index] = 0;
    }

    if(start_index > update_end || end_index < update_start)
        return;

    if(start_index >= update_start && end_index <= update_end){
        segment_tree[segment_index] += change;
        if(start_index != end_index){
            LazyTree[2 * segment_index] += change;
            LazyTree[2 * segment_index + 1] += change;
        }
        return;
    }

    int mid = (start_index + end_index) / 2;
    RangeUpdate(start_index, mid, 2 * segment_index, update_start, update_end, change);
    RangeUpdate(mid + 1, end_index, 2 * segment_index + 1, update_start, update_end, change);

    segment_tree[segment_index] = min(segment_tree[2 * segment_index], segment_tree[2 * segment_index + 1]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ar.resize(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    segment_tree.resize(4 * n, INF);
    LazyTree.resize(4 * n, 0);

    buildTree(0, n - 1, 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r;
            cin >> l >> r;
            cout << findQuery(0, n - 1, 1, l, r) << "\n";
        }
        else if(type == 2) {
            int l, r, val;
            cin >> l >> r >> val;
            RangeUpdate(0, n - 1, 1, l, r, val);
        }
        else if(type == 3) {
            int pos, val;
            cin >> pos >> val;
            PointUpdate(0, n - 1, 1, pos, val);
        }
    }

    return 0;
}
