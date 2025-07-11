#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int> arr[N];
vector<bool> vis(N,false);
vector<int>height(N,0);
void dfs(int root, int curr_height){
    vis[root] = true;
    height[root] = curr_height;
    for(auto child : arr[root]){
        if(vis[child]) continue;
        dfs(child, curr_height + 1);
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
    dfs(1,0);
    int ans=INT_MAX;
    for(int i=2;i<=n;++i){
        if(height[i]<ans)ans=height[i];
    }
    cout<<"The Single Shortest Path length for the given tree with root as 1 is: "<<ans<<endl;
    return 0;
}

 