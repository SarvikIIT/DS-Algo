// We study to check if one is a subtree of other using the logic on in and out timings


#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> arr[N];
vector<bool>vis(N,false);
vector<int>intime(N),outtime(N);

int timer=1;
void dfs(int root){
    vis[root]=true;
    intime[root]=timer++;
    for(auto child:arr[root]){
        if(vis[child])continue;
        dfs(child);
    }
    outtime[root]=timer++;
}


int main(){
    int n;
    cin>>n;
    int v1,v2;
    for(int i=0;i<n;++i){
        cin>>v1>>v2;
        arr[v1].push_back(v2);
        arr[v2].push_back(v1);
    }
    dfs(1);
    int v3,v4;
    cin>>v3>>v4;
    if(intime[v3]<intime[v4] && outtime[v3]>outtime[v4])cout<<v4<<" is a subtree of: "<<v3<<endl;
    else cout<<"Not a subtree"<<endl;


    return 0;
}