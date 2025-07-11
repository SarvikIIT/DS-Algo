#include<bits/stdc++.h>
using namespace std;

#define N 1000

bool vis[N];
vector<int> arr[N];
queue<int> q;

void bfs(int v){
	vis[v]=true;
	q.push(v);
	while(!q.empty()){
		int curr= q.front();
		q.pop();
		for(auto child: arr[curr]){
			if(!vis[child]){q.push(child);
			vis[child]=true;}
		}
	}
}



int main(){
	return 0;
}