#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = 42;
	int b = 76;
	int and_val = a & b;
	int or_val = a | b;
	int xor_val = a ^ b;
	int not_val = ~ a;
	int two_complement = ~a + 1;
	int leftshift = a<<2; // a ke saare bits 2 left shifted 000....101 (3) --> 0000...10100 (20) 
	int rightshift = a>>2 // a ke saare bits 2 right shifted 000....101 (3) --> 0000...1 (1)
	return 0;
}