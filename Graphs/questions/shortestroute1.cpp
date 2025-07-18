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
using vi = vector<int>;
using vpii = vector<pair<int, int>>;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 2e5 + 5;

int n, m;
vector<vpii> ar;
vector<int> dis;
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

void Dijkstra(int root) {
    dis[root] = 0;
    pq.push({0, root});

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int curr_dis = top.first;
        int curr_node = top.second;
        if (curr_dis > dis[curr_node]) continue;
        for (auto child : ar[curr_node]) {
            int weight = child.first;
            int next_node = child.second;
            int new_dis = curr_dis + weight;

            if (dis[next_node] > new_dis) {
                dis[next_node] = new_dis;
                pq.push({new_dis, next_node});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    ar.assign(n + 1, {});
    dis.assign(n + 1, INF);

    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        ar[a].pb({c, b});
    }

    Dijkstra(1);

    rep(i, 1, n + 1) {
        cout << dis[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
