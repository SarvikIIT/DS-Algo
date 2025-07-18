#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
char dir[4] = {'D', 'R', 'L', 'U'};
 
int n, m;
 
bool isValid(int x, int y, const vector<string> &grid) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
 
    const int INF = 1e15;
    vector<vector<int>> monsterDist(n, vector<int>(m, INF));
    vector<vector<int>> playerDist(n, vector<int>(m, INF));
    vector<vector<pii>> parent(n, vector<pii>(m, make_pair(-1, -1)));
 
    queue<pii> q;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push(make_pair(i, j));
                monsterDist[i][j] = 0;
            }
        }
    }
 
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        int x = curr.first, y = curr.second;
 
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny, grid) && monsterDist[nx][ny] > monsterDist[x][y] + 1) {
                monsterDist[nx][ny] = monsterDist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    pii start = make_pair(-1, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'A') start = make_pair(i, j);
 
    if (start.first == -1) {
        cout << "NO\n";
        return 0;
    }
 
    while (!q.empty()) q.pop();
    q.push(start);
    playerDist[start.first][start.second] = 0;
 
    pii escape = make_pair(-1, -1);
 
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        int x = curr.first, y = curr.second;
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            escape = curr;
            break;
        }
 
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (!isValid(nx, ny, grid)) continue;
            if (playerDist[nx][ny] > playerDist[x][y] + 1 &&
                playerDist[x][y] + 1 < monsterDist[nx][ny]) {
                playerDist[nx][ny] = playerDist[x][y] + 1;
                parent[nx][ny] = make_pair(x, y);
                q.push(make_pair(nx, ny));
            }
        }
    }
 
    if (escape.first == -1) {
        cout << "NO\n";
        return 0;
    }
    string path;
    pii cur = escape;
    while (cur != start) {
        pii p = parent[cur.first][cur.second];
        for (int d = 0; d < 4; d++) {
            if (p.first + dx[d] == cur.first && p.second + dy[d] == cur.second) {
                path += dir[d];
                break;
            }
        }
        cur = p;
    }
    reverse(path.begin(), path.end());
 
    cout << "YES\n";
    cout << (int)path.size() << "\n";
    cout << path << "\n";
 
    return 0;
}