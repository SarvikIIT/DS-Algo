#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> isPrime;
vector<int> PowersofPrime;
int ans = 1;

void PrimeSieve(int n) {
    isPrime.assign(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
        if(isPrime[i]) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void PrimeFactors(int num) {
    for(int i = 2; i * i <= num; ++i) {
        if(isPrime[i]) {
            while(num % i == 0) {
                num /= i;
                PowersofPrime[i]++;
            }
        }
    }
    if(num > 1) PowersofPrime[num]++;
}

int TotalDivisors() {
    ans = 1;
    for(int i = 2; i <= n; ++i) {
        if(PowersofPrime[i] != 0)
            ans *= (PowersofPrime[i] + 1);
    }
    return ans;
}

int main() {
    cin >> n;
    PrimeSieve(n);
    PowersofPrime.assign(n+1, 0);

    PrimeFactors(n);
    cout << TotalDivisors() << "\n";

    return 0;
}
