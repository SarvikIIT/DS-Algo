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

ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll power(ll x, ll y) { ll res = 1; x = x % MOD; while (y > 0) { if (y & 1) res = mul(res, x); x = mul(x, x); y = y >> 1; } return res; }

ll gcd(ll a, ll b) { if (b > a) return gcd(b, a); if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

void solve() {
    int h, w;
    cin>>h>>w;
    vector<string> grid(h);
    for (int i = 0; i < h; ++i) cin >> grid[i];
    vector<vector<int>> dp(h, vector<int>(w, 0));
    if (grid[0][0] == '.') dp[0][0] = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') continue;
            if (i > 0 && grid[i - 1][j] == '.' && dp[i - 1][j] > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            if (j > 0 && grid[i][j - 1] == '.' && dp[i][j - 1] > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            ans = max(ans, dp[i][j]);

    cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;  // comment this line if single test case
    while(t--) solve();
    return 0;
}
    