#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int ar[MAX];
int n, m, k;

bool CanBePlaced(int pos) {
    int used = 0;
    int i = pos;
    while (used < m && i <= n) {
        int left_vol = k;
        while (i <= n && ar[i] <= left_vol) {
            left_vol -= ar[i++];
        }
        used++;
    }
    return i == n + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    int ans = 0;
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (CanBePlaced(mid)) {
            ans = max(ans, n - mid + 1);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
