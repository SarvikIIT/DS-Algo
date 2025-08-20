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
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

inline void fastscan(int& number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
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
template<typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;

template<typename T>
using safe_set = unordered_set<T, custom_hash>;

template<typename K>
using safe_unordered_set = unordered_set<K, custom_hash>;

template<typename K, typename V>
using safe_unordered_map = unordered_map<K, V, custom_hash>;

// Function to take input of an array
template<typename T>
inline void take(vector<T>& arr, int start, int end) {
    rep(i, start, end) cin >> arr[i];
}

// Function to take input of a 2D array
template<typename T>
inline void take2D(vector<vector<T>>& arr, int start_row, int end_row, int start_col, int end_col) {
    rep(i, start_row, end_row) {
        rep(j, start_col, end_col) {
            cin >> arr[i][j];
        }
    }
}

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
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    invfact[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) {
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}
inline ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

class SegmentTree {
private:
    vi ar, segment_tree, lazy;
    int n;

public:
    SegmentTree(vi& arr) {
        ar = arr;
        n = sz(arr);
        segment_tree.resize(4 * n, INF);
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

        segment_tree[segment_index] = min(segment_tree[2 * segment_index], segment_tree[2 * segment_index + 1]);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            segment_tree[node] += lazy[node];
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
        segment_tree[node] = min(segment_tree[2 * node], segment_tree[2 * node + 1]);
    }

    int query(int start_index, int end_index, int segment_index, int query_start, int query_end) {
        push(segment_index, start_index, end_index);
        if (query_end < start_index || query_start > end_index)
            return INF;
        if (query_start <= start_index && end_index <= query_end)
            return segment_tree[segment_index];

        int mid = (start_index + end_index) / 2;
        int left = query(start_index, mid, 2 * segment_index, query_start, query_end);
        int right = query(mid + 1, end_index, 2 * segment_index + 1, query_start, query_end);

        return min(left, right);
    }

    int rangeMin(int l, int r) {
        return query(0, n - 1, 1, l, r);
    }

    void updateRange(int l, int r, int val) {
        rangeUpdate(1, 0, n - 1, l, r, val);
    }
};

class DSU {
private:
    vi parent, rank, size;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        rep(i, 0, n) parent[i] = i;
    }

    inline int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    inline void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
            size[py] += size[px];
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
            size[px] += size[py];
        }
        else {
            parent[py] = px;
            rank[px]++;
            size[px] += size[py];
        }
    }

    inline bool same(int x, int y) {
        return find(x) == find(y);
    }

    inline int getSize(int x) {
        return size[find(x)];
    }
};

inline bool isPalindrome(string s) {
    int n = sz(s);
    rep(i, 0, n / 2) if (s[i] != s[n - 1 - i]) return false;
    return true;
}

inline string toBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = char('0' + n % 2) + binary;
        n /= 2;
    }
    return binary.empty() ? "0" : binary;
}

inline int fromBinary(string binary) {
    int num = 0;
    for (char c : binary) {
        num = num * 2 + (c - '0');
    }
    return num;
}

inline bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

const vi dx = { -1, 0, 1, 0, -1, -1, 1, 1 };
const vi dy = { 0, 1, 0, -1, -1, 1, -1, 1 };

inline int countBits(int n) {
    return __builtin_popcountll(n);
}

inline int lowestBit(int n) {
    return n & (-n);
}

inline bool isPowerOfTwo(int n) {
    return n && !(n & (n - 1));
}

template<typename T>
inline void sortVector(vector<T>& arr) {
    sort(all(arr));
}

template<typename T>
inline void reverseVector(vector<T>& arr) {
    reverse(all(arr));
}


int n;
string s;

void solve() {
    cin >> n >> s;
    //Processing the number required:
    int val = 0;
    for (int i = 0; i < n; ++i) {
        val = (val << 1) | (s[i] - '0');
    }
    // DP table: expected moves to reach one from i -->dp[i]
    const long long INV2 = (MOD + 1) / 2; // modular inverse of 2
    vector<ll> dp(val + 2, 0);
    dp[1] = 0; // steps to reach 1 from 1 is 0
    dp[2] = 1; // both floor and ceil of 2 is 1 hence...

    // trailin gbit one so the case is :
    for (long long i = 2; i <= val; ++i) {
        if ((i & 1LL) == 0) {
            dp[i] = add(1, dp[i >> 1]);
        }
        else {
            long long a = dp[i >> 1];
            long long b = dp[(i >> 1) + 1];
            dp[i] = add(1, mul(INV2, add(a, b)));
        }
    }

    cout << dp[val] << endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // precompute_factorials();

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}




