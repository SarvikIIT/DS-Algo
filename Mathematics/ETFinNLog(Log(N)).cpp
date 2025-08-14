#include<bits/stdc++.h>
using namespace std;
vector<int> phi(1e6+1,0)
void init(MAXN){
	for(int i=1;i<=MAXN;++i)phi[i]=i;

	for(int i=2;i<=MAXN;++i){
		if(phi[i]==i){
			for(int j=1;j<+MAXN;j+=i){
				phi[j]/=i;
				phi[j]*=i-1;
			}
		}
	}
}
int main(){
	init(100000);
}