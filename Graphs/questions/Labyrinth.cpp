#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,a,b) for(int i = a; i < b; i++)

const int N = 1001;
int n, m;
char grid[N][N];
bool vis[N][N];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
char dir[] = {'D', 'R', 'L', 'U'};

int start_x, start_y;
vector<char> bestPath;

bool isPossible(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (grid[x][y] == '#') return false;
    return true;
}


void dfs(int x, int y, vector<char>& path) {
    if (grid[x][y] == 'B') {
        if (bestPath.empty() || path.size() < bestPath.size()) {
            bestPath = path;
        }
        return;
    }

    vis[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (isPossible(newx, newy) && !vis[newx][newy]) {
            path.push_back(dir[i]);
            dfs(newx, newy, path);
            path.pop_back(); 
        }
    }

    vis[x][y] = false;
}

void solve() {
    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    vector<char> currentPath;
    dfs(start_x, start_y, currentPath);

    if (!bestPath.empty()) {
        cout << "YES" << endl;
        cout << bestPath.size() << endl;
        for (char c : bestPath) cout << c;
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
