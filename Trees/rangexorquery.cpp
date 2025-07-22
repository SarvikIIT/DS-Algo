#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)
#define each(a,x) for (auto& a : x)

using ll = long long;
using vi = vector<int>;

const int INF = 1e18;

class SegmentTree {
private:
    vi ar, segment_tree, lazy;
    int n;

public:
    SegmentTree(vi& arr) {
        ar = arr;
        n = sz(arr);
        segment_tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildTree(0, n - 1, 1);
    }

    void buildTree(int start_index, int end_index, int segment_index) {
        if (start_index == end_index) {
            segment_tree[segment_index] = ar[start_index];
            return;
        }

        int mid = (start_index + end_index) / 2;
        buildTree(start_index, mid, 2 * segment_index);
        buildTree(mid + 1, end_index, 2 * segment_index + 1);

        segment_tree[segment_index] = segment_tree[2 * segment_index] ^ segment_tree[2 * segment_index + 1];
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            int segment_length = end - start + 1;
            if (segment_length % 2 == 1) {
                segment_tree[node] ^= lazy[node];
            }
            if (start != end) {
                lazy[2 * node] ^= lazy[node];
                lazy[2 * node + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void rangeUpdate(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (start > r || end < l) return;

        if (start >= l && end <= r) {
            lazy[node] ^= val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        rangeUpdate(2 * node, start, mid, l, r, val);
        rangeUpdate(2 * node + 1, mid + 1, end, l, r, val);

        segment_tree[node] = segment_tree[2 * node] ^ segment_tree[2 * node + 1];
    }

    int query(int start_index, int end_index, int segment_index, int query_start, int query_end) {
        if (query_end < start_index || query_start > end_index) return 0;

        push(segment_index, start_index, end_index);

        if (query_start <= start_index && end_index <= query_end) {
            return segment_tree[segment_index];
        }

        int mid = (start_index + end_index) / 2;
        int left = query(start_index, mid, 2 * segment_index, query_start, query_end);
        int right = query(mid + 1, end_index, 2 * segment_index + 1, query_start, query_end);

        return left ^ right;
    }

    int rangeXor(int l, int r) {
        return query(0, n - 1, 1, l, r);
    }

    void updateRange(int l, int r, int val) {
        rangeUpdate(1, 0, n - 1, l, r, val);
    }
};

// ----------------------- Solve function -----------------------

int n, q;
vi x;

void solve() {
    cin >> n >> q;
    x.resize(n);
    rep(i, 0, n) cin >> x[i];
    SegmentTree st(x);

    while (q--) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        cout << st.rangeXor(a,b) << endl;
        
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
