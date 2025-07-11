#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int m;
const int N = 1e6+10;
long long trees[N];

bool isWoodSufficient(int h){
    long long int woodCollected=0;
    for(int i=0;i<n;++i){
        if(trees[i]-h>=0)woodCollected+=(trees[i]-h);
    }
    return woodCollected>=m;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>trees[i];
    }
    long long lo=0,hi=1e9,mid;

    while(hi-lo>1){
        mid=(hi+lo)/2;
        if(isWoodSufficient(mid)){
            lo=mid+1;
        }
        else{hi=mid;}
    }

    if(!isWoodSufficient(lo))cout<<lo-1;
    else if(!isWoodSufficient(hi))cout<<hi-1;
     
}