
//Using Memoisation:

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


int n,x;
vi c;
int dp[N][101];


int soln(int x,int index){
    if(x==0)return 1;
    if(index>=n)return 0;
    if(dp[x][index]!=-1)return dp[x][index];
    int val=0;
    for (int i= 0; c[index]*i<=x;++i) {
        val += soln(x -c[index]*i,index + 1);
    }
    return dp[x][index]=val;
}


void solve() {
    cin>>n>>x;
    c.resize(n);
    memset(dp,-1,sizeof(dp));
    rep(i,0,n)cin>>c[i];
    cout<<soln(x,0)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;  // comment this line if single test case
    while(t--) solve();
    return 0;
}


//Bottom Up Solution:


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
const int N = 1e6 + 5; 

ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll power(ll x, ll y) { ll res = 1; x = x % MOD; while (y > 0) { if (y & 1) res = mul(res, x); x = mul(x, x); y = y >> 1; } return res; }

ll gcd(ll a, ll b) { if (b > a) return gcd(b, a); if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

int n, x;
vi a;

void solve() {
    cin >> n >> x;
    a.resize(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> curr(x + 1), nxt(x + 1);
    rep(i, 0, n + 1) curr[0] = nxt[0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int sum = 0; sum <= x; sum++) {
            int skipping = nxt[sum];
            int picking = (sum >= a[i]) ? curr[sum - a[i]] : 0;
            curr[sum] = (skipping + picking) % MOD;
        }
        swap(curr, nxt);
    }

    cout << nxt[x] << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
    return 0;
}

    