#include <bits/stdc++.h>
using namespace std;
string r;
int have[3];
int price[3];
int req[3];
long long money;

bool CanBeMade(long long x) {
    long long req_money = 0;
    req_money += max(0LL, x * req[0] - have[0]) * price[0];
    req_money += max(0LL, x * req[1] - have[1]) * price[1];
    req_money += max(0LL, x * req[2] - have[2]) * price[2];
    return req_money <= money;
}

int main() {
    cin >> r;
    for (int i = 0; i < r.size(); ++i) {
        if (r[i] == 'B') req[0]++;
        else if (r[i] == 'S') req[1]++;
        else req[2]++;
    }
    for (int i = 0; i < 3; ++i) cin >> have[i];
    for (int i = 0; i < 3; ++i) cin >> price[i];
    cin >> money;

    long long lo = 0, hi = 1e13, mid;
    while (hi - lo > 1) {
        mid = (hi + lo) / 2;
        if (CanBeMade(mid)) lo = mid + 1;
        else hi = mid;
    }
    if (!CanBeMade(lo)) cout << lo - 1 << endl;
    else if (!CanBeMade(hi)) cout << hi - 1 << endl;
    else cout << "0" << endl;
}
