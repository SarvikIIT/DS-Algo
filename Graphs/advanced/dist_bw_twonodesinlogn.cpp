#include <bits/stdc++.h>
using namespace std;

//Things learnt Sparse Table , Binary Lifting  and Advanced Implementation of This
const int N = 1000;
const int maxN = log2(N) + 1;

vector<int> ar[N + 1];
int sparse[N + 1][maxN];     // here sparse[i][j] stores the (2^j) th parent of i
bool vis[N + 1];
int height[N + 1];

void dfs(int root, int parent) {
	vis[root] = true;
	sparse[root][0] = parent;

	for (auto child : ar[root]) {
		if (vis[child]) continue;  // Since it is a tree either use this or child == parent as tree has no cycle
		height[child] = height[root] + 1;
		dfs(child, root);
	}
}

void FillSparseTable(int root) {
	dfs(root, -1); // Fills the direct parent and we wont use it again and again as it would give TLE hence we just use DP hereafter:

	// We know 2^i == 2* 2^(i-1), hence we use the parent array and fill the table accordingly

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j < maxN; ++j) {                             // O(NlogN)
			if (sparse[i][j - 1] != -1) {
				int par = sparse[i][j - 1];
				sparse[i][j] = sparse[par][j - 1];
			}
		}
	}
}

int LCA(int a, int b) {
	if (height[a] > height[b]) swap(a, b);

	int d = height[b] - height[a];
	while (d > 0) {
		int i = log2(d);
		b = sparse[b][i];
		d -= (1 << i);
	}
	if (a == b) return a;

	for (int i = maxN - 1; i >= 0; --i) {
		if (sparse[a][i] != -1 && sparse[a][i] != sparse[b][i]) {
			a = sparse[a][i];
			b = sparse[b][i];
		}
	}
	return sparse[a][0];
}

int dist(int a,int b){
	return( dist[a]+dist[b]-2* LCA(a,b));
}

int main() {
	//Temporarily fill the entire table with -1:
	memset(sparse, -1, sizeof(sparse));

	return 0;
}
