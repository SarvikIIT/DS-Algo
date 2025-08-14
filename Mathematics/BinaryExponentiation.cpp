int BinaryExponentiation(int base,int power){
	if(power==0)return 1;
	int res = BinaryExponentiation(base,power/2);
	if(power%2==0)return res*res;
	else return res*res*base;
}
