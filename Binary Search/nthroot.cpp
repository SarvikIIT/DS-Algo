#include<bits/stdc++.h>
using namespace std;
    //Binary Exponentiation
    double binPow(double x,int n){
        if(n==0)return 1;

        double res=binPow(x,n/2);
        if(n%2==0)return res*res;
        if(n%2==1)return res*res*x;

    }


double eps=1e-6;

//Nth root logic
int main(){
    double x;
    cin>>x;
    int pow;
    cin>>pow;
    double lo=0,hi=x,mid;
    while(hi-lo>eps){
        mid=(hi+lo)/2;
        if(binPow(mid,pow)<x)lo=mid;
    
    else hi=mid;
    }
    cout<<lo<<endl;
}