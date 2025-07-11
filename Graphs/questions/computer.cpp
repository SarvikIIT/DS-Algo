
// BFS with parent vector:

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


int n,m;
vi ar[N];
int cnt;
vector<bool> vis(N,false);
vi val;
queue<int>q;
vector<int>h(N+1,INF),parent(N + 1);

void bfs(int root){
    vis[root] = true;
    q.push(root);
    h[root] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto child : ar[curr]){
            if(!vis[child]){
                h[child] = h[curr] + 1;
                parent[child] = curr;  
                vis[child] = true;
                q.push(child);
            }
        }
    }
}



void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    bfs(1);

    if(h[n] == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << h[n] << endl;
        vi v = {n};
        while(v.back() != 1)
            v.pb(parent[v.back()]);
        reverse(all(v));
        for(int t : v)
            cout << t << " ";
        cout << endl;
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;  // comment this line if single test case
    while(t--) solve();
    return 0;
}
    