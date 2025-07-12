#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int countset(int x) {
    if (x == 0) return 0;

    int msb = (int)log2(x);
    int pow2msb = 1LL << msb;

    int bitsUptoPow2 = msb * (pow2msb >> 1); 
    int msbBits = x - pow2msb + 1;       
    int rest = countset(x - pow2msb); 

    return bitsUptoPow2 + msbBits + rest;
}

void solve() {
    int n;
    cin >> n;
    cout << countset(n) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
