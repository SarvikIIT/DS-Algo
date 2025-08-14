/*
												QUESTION:
		Here is the following game, played by two players who take turns moving.
		At the beginning there are n coins. When it is a player’s turn he can take away 1, 3 or 4 coins.
		The player who takes the last one away is declared the winner 
		(in other words, the player who can not make a move is the loser).
		The question is: For what n will the first player win if they both play optimally?
*/


#include <bits/stdc++.h>
using namespace std;

int WhoWins(int n, int player_id) {
	if (n == 1 || n == 3 || n==4 )return player_id; // Player 1 wins
	return  WhoWins(n - 1, 1 - player_id) &&
			WhoWins(n - 3, 1 - player_id) &&
			WhoWins(n - 4, 1 - player_id) ? 1 - player_id : player_id; // Player 2 wins

}



int main() {
	int n;
	cin >> n;
	int ans = WhoWins(n,0);
	cout << (ans ? "First" : "Second") << endl;
	return 0;
}