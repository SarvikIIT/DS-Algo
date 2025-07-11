#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> arr[N];
vector<bool> vis(N, false);
vector<int> height(N, 0);
vector<int> par(N, -1);

void dfs(int root, int h , int parent){
	vis[root]=true;
	height[root]=h;
	par[root]=parent;
	for(auto child : arr[root]){
		if(vis[child])continue;
		else dfs(child,h+1,root);
	}
}

int FindHeight(int root){
	return height[root];
}

int LCA(int a,int b){
	int h1 = FindHeight(a);
	int h2 = FindHeight(b);
	if(h1<h2){
		swap(a,b);
		swap(h1,h2);
	}
	while(h1>h2){
		a=par[a];
		h1--;
	}
	if(a==b)return a;
	while(par[a]!=par[b]){
		a=par[a];
		b=par[b];
	}
	return par[a];
}

int main(){
	int n;
    cin >> n;

    // Reading tree edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // Run DFS to set parent and height
    dfs(1, 0, -1); // assuming 1 as root

    // Example queries
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << "LCA of " << a << " and " << b << " is: " << LCA(a, b) << endl;
    }

	return 0;
}