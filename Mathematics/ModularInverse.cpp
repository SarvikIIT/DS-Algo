#include<bits/stdc++.h>
using namespace std;
#define int long long;

const int MOD = 998244353;

int binPow(int base,int power){
	if(power==0)return 1;

	int res = binPow(base,power/2);
	if(power%2==0)return ((res%MOD)*(res%MOD))%MOD;
	else return (((((res%MOD)*(res%MOD))%MOD)*(base%MOD))%MOD);
}

int n;

void solve(){

	cin>>n;
	cout<<binPow(Number,Modulo-2)<<endl;

}



signed main(){
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}