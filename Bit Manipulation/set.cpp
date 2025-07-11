#include<bits/stdc++.h>
using namespace std;


int GenerateBitmask(const vector<int>& sets){
	int x = 0;
	for(int i=0;i<sets.size();++i) x | = (1<<sets[i]);
	return x;
}

void ShowSet(const vector<int>& sets){

	for(int i=0;i<32;++i)
		if (x&(1<<i)) cout << i << " ";

	cout<<endl;

	return;
}

int hamming(string a, string b) {
	int d = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] != b[i]) d++;
	}
	return d;
}


int main(){


	int sets = { 1 , 3 , 4 , 8 };


	// Making this set in a bitmask of a int :


	int bitmask = GenerateBitmask(sets);  
	cout << __builtin_popcount(bitmask); // the only set bits are 1st 3rd 4th and 8th....


	// Retrieving the Set :


	ShowSet(sets);


	// Set Operations :


	int union = 1<<1 | 1<<3 | 1<<4 | 1<<8 ; // taking or of all the bits:

	int intersection = 1<<1 & 1<<3 & 1<<4 & 1<<8 ; // taking only the common bits in two sets:

	int complement = ~ a // turning of only the on bits:

	int difference = a | ~b;   // a/b ke liye


	// Iterating through the Subsets :


	for(int i=0;i<(1<<n);++i){} // Process all subsets till n-1 { 0 , 1 , 2 , 3 .... n-1 }:

	for(int i=0;i<(1<<n);++i)
		if(__builtin_popcount(i)==k){}          //Process subsets of size k :


	for(int i=0; i = i -b & b;){}    // Process all the subsets of the bitmask number b : Just dry run to verify....



// Hamming Distance:The Hamming distance hamming(a,b) between two strings a and b of equal length is the number of positions where the strings differ

	int ham = hamming( a , b );

	return 0;
}