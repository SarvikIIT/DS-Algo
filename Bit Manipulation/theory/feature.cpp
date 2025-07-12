#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = 42;  // 0000...101010;
	int leading_zeroes = __builtin_clz(a); //26
	int trailing_zeroes = __builtin_ctz(a); //1
	int set_bits = __builtin_popcount(a); //3
	int even_odd_numbers_of_one = --builtin_parity(a); // 1 for odd and 0 for even
	return 0;
}