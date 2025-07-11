#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> req;
vector<int> has;

bool CanBeMade(int x) {
    long long deficit = 0;
    for (int i = 0; i < n; ++i) {
        deficit += max(0LL, 1LL * x * req[i] - has[i]);
        if (deficit > k) return false;
    }
    return deficit <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    req.resize(n);
    has.resize(n);

    for (int i = 0; i < n; ++i) cin >> req[i];
    for (int i = 0; i < n; ++i) cin >> has[i];

    int lo = 0, hi = 2000000000, mid;

    while (hi - lo > 1) {
        mid = (hi + lo) / 2;
        if (CanBeMade(mid)) lo = mid + 1;
        else hi = mid;
    }

    if (!CanBeMade(lo)) cout << lo - 1 << "\n";
    else cout << hi - 1 << "\n";

    return 0;
}
