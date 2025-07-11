#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> arr[N];
vector<bool>vis(N,false);

void dfs(int root){
    vis[root]=true;
    cout<<"Node now visited: "<<root<<endl;
    for(auto child:arr[root]){
        if(vis[child])continue;
        dfs(child);
    }
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

    return 0;
}