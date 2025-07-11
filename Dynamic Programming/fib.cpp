#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
//Memoisation:
int fib(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fib(n-1)+fib(n-2);
}


int main(){
    int n;
    cin>>n;
    dp.assign(n + 1, -1);
    int ans= fib(n);
    cout<<ans<<endl;


    //Bottom's Up
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[n]<<endl;


    return (0);
}