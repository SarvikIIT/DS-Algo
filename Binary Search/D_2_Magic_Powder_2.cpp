#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
vector<long long> req, has;

bool CanBeMade(long long x) {
    long long deficit = 0;
    for (int i = 0; i < n; ++i) {
        if (req[i] > 0 && x > LLONG_MAX / req[i]) {
            return false;
        }
        long long need = x * req[i];
        if (need > has[i]) {
            deficit += (need - has[i]);
            if (deficit > k) return false;
        }
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

    long long lo = 0, hi = 100000000000LL;

    while (hi - lo > 1) {
        long long mid = (hi + lo) / 2;
        if (CanBeMade(mid)) lo = mid;
        else hi = mid - 1;
    }

    if (CanBeMade(hi)) cout << hi << "\n";
    else cout << lo << "\n";

    return 0;
}
