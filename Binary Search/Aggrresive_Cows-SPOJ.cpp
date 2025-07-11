#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
int n,cows;
int pos[N];

bool isPlaceable(int min){
    int lastPlace=-1;
    int cows_cnt=cows;
    for(int i=0;i<n;++i){
        if(pos[i]-lastPlace>=min||lastPlace==-1){cows_cnt--,lastPlace=pos[i];}
        if(cows_cnt==0)break;
    }
    return cows_cnt==0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>cows;
        for(int i=0;i<n;++i){
            cin>>pos[i];
        }
        sort(pos,pos+n);
int lo=0,hi=1e9,mid;
    while(hi-lo>1){
        mid=(hi+lo)/2;
        if(isPlaceable(mid))
            lo=mid;
        else hi=mid-1;
    }
if(isPlaceable(hi))cout<<hi<<endl;
    else cout<<lo<<endl;



    }



    
    
}