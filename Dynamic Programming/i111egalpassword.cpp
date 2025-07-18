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

const ll MOD = 998244353;
const ll INF = 1e18;
const int N = 2e5 + 5;

ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll power(ll x, ll y) { ll res = 1; x = x % MOD; while (y > 0) { if (y & 1) res = mul(res, x); x = mul(x, x); y = y >> 1; } return res; }

ll gcd(ll a, ll b) { if (b > a) return gcd(b, a); if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

int n;

void solve() {
    cin >> n;

    vvi dp(10, vi(n + 1, 0));

    for (int i = 1; i <= 9; ++i) {
        dp[i][1] = 1;
    }
    

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= 9; ++i) {
            dp[i][len] = dp[i][len - 1];
            if (i > 1) dp[i][len] = add(dp[i][len], dp[i - 1][len - 1]);
            if (i < 9) dp[i][len] = add(dp[i][len], dp[i + 1][len - 1]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        ans = add(ans, dp[i][n]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
