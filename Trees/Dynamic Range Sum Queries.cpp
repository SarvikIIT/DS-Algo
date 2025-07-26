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
using ld = long double;
using str = string;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

inline void fastscan(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
inline ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
inline ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
inline ll power(ll x, ll y) { 
    ll res = 1; 
    x = x % MOD; 
    while (y > 0) { 
        if (y & 1) res = mul(res, x); 
        x = mul(x, x); 
        y = y >> 1; 
    } 
    return res; 
}

inline ll gcd(ll a, ll b) { 
    if (b > a) return gcd(b, a); 
    if (b == 0) return a; 
    return gcd(b, a % b); 
}
inline ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
inline bool isPrime(int n) { 
    if (n <= 1) return false; 
    if (n <= 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) return false; 
    return true; 
}

vector<ll> fact(N), invfact(N);
void precompute_factorials() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = mul(fact[i-1], i);
    }
    invfact[N-1] = power(fact[N-1], MOD-2);
    for(int i = N-2; i >= 0; i--) {
        invfact[i] = mul(invfact[i+1], i+1);
    }
}
inline ll nCr(int n, int r) {
    if(r > n || r < 0) return 0;
    return mul(fact[n], mul(invfact[r], invfact[n-r]));
}

class SegmentTree {
private:
    vi ar, segment_tree, lazy;
    int n;
    
public:
    SegmentTree(vi& arr) {
        ar = arr;
        n = sz(arr);
        segment_tree.resize(4 * n, 0); // For sum, use 0
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

        segment_tree[segment_index] = segment_tree[2 * segment_index] + segment_tree[2 * segment_index + 1];
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            segment_tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void rangeUpdate(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        rangeUpdate(2 * node, start, mid, l, r, val);
        rangeUpdate(2 * node + 1, mid + 1, end, l, r, val);
        segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
    }

    int query(int start_index, int end_index, int segment_index, int query_start, int query_end) {
        push(segment_index, start_index, end_index);
        if (query_end < start_index || query_start > end_index)
            return 0; // For sum, return 0
        if (query_start <= start_index && end_index <= query_end)
            return segment_tree[segment_index];

        int mid = (start_index + end_index) / 2;
        int left = query(start_index, mid, 2 * segment_index, query_start, query_end);
        int right = query(mid + 1, end_index, 2 * segment_index + 1, query_start, query_end);

        return left + right;
    }
    
    int rangeSum(int l, int r) {
        return query(0, n - 1, 1, l, r);
    }
    
    void updateRange(int l, int r, int val) {
        rangeUpdate(1, 0, n - 1, l, r, val);
    }
};

int n, q;
vi x;

void solve() {
    cin >> n >> q;
    x.resize(n);
    rep(i, 0, n) cin >> x[i];
    SegmentTree st(x);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int old, naya;
            cin >> old >> naya;
            old--;
            int curr = st.rangeSum(old, old);
            st.updateRange(old, old, naya - curr);
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << st.rangeSum(a, b) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // precompute_factorials();
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}