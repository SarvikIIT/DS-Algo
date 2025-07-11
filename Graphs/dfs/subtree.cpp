
// Done in O(N)

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> arr[N];
vector<bool>vis(N,false);
vector<int>subsize(N,1);
void dfs(int root,int parent){
    vis[root]=true;
    
   // cout<<"Node now visited: "<<root<<endl;
    for(auto child:arr[root]){
        if(child==parent)continue;
        dfs(child,root);
        
            subsize[root]+=subsize[child];
        
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
    dfs(1,-1);

    for (int i = 1; i <= n; ++i) {
        cout << "Subtree size of node " << i << " = " << subsize[i] << endl;
    }

    return 0;
}