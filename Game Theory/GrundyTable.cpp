/*
												QUESTION:

You are given two piles of stones, one with A stones and one with B stones.

Two players play alternately.
On each turn, a player must choose exactly one of the following moves:

Remove 2 stones from one pile and 1 stone from the other.

Remove 3 stones from one pile and 1 stone from the other.

The player who cannot make a move loses.
Both players play optimally.

Input

The first line contains an integer T — the number of test cases.

Each of the next T lines contains two integers A and B.

Output

For each test case, print:

"YES" if the first player can force a win.

"NO" otherwise.

Constraints

   0≤A,B≤500 1≤T≤1000
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 501;
int grundy[MAX][MAX];


int mex(set<int>& s) {
	int m = 0;
	while (s.find(m) != s.end()) {
		m++;
	}
	return m;
}


int main() {
	// Precompute Grundy table once
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			set<int> s;
			// Move (2,1)
			if (i >= 2 && j >= 1) s.insert(grundy[i - 2][j - 1]);
			if (i >= 1 && j >= 2) s.insert(grundy[i - 1][j - 2]);
			// Move (3,1)
			if (i >= 3 && j >= 1) s.insert(grundy[i - 3][j - 1]);
			if (i >= 1 && j >= 3) s.insert(grundy[i - 1][j - 3]);
			grundy[i][j] = mex(s);
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (grundy[a][b] != 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
