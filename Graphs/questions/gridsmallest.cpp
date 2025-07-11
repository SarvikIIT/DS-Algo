#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int N, M;

char grid[MAXN][MAXN];
int Dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int Dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool isValid(int x, int y, char last, vector<vector<bool>>& vis) {
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    if (vis[x][y]) return false;
    return (grid[x][y] - last == 1);
}

int dfs(int x, int y, vector<vector<bool>>& vis) {
    vis[x][y] = true;
    int maxLength = 1;

    for (int i = 0; i < 8; ++i) {
        int nx = x + Dx[i];
        int ny = y + Dy[i];
        if (isValid(nx, ny, grid[x][y], vis)) {
            maxLength = max(maxLength, 1 + dfs(nx, ny, vis));
        }
    }
    vis[x][y] = false;
    return maxLength;
}

int main() {
    cin >> N >> M;
    vector<vector<bool>> vis(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int start_x, start_y;
    cin >> start_x >> start_y;

    int result = dfs(start_x, start_y, vis);
    cout <<"Case 1: "<< result << endl;

    return 0;
}
