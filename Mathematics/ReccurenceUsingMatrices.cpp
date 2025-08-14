#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size(), m = B[0].size(), p = A[0].size();
    vector<vector<int>> C(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < p; ++k)
            for (int j = 0; j < m; ++j)
                C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
    return C;
}

vector<vector<int>> MatrixPower(vector<vector<int>> base, int exponent) {
    int n = base.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            res = mul(res, base);
        base = mul(base, base);
        exponent /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, exponent; cin >> n >> exponent;
        vector<vector<int>> input = {
            {1, 2},
            {0, 3}
        };
        vector<vector<int>> basecase = {
            {1, 0}
        };

        vector<vector<int>> powered = MatrixPower(input, exponent);
        vector<vector<int>> result = mul(basecase, powered);

        cout << result[0][1] << "\n";
    }
    return 0;
}
