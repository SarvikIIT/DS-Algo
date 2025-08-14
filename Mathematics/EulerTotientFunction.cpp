int gcd(int a,int b){
	if b>a return gcd(b,a);
	if(b==0)return a;
	return gcd(b,a%b);
}

//For Prime number(n):all till n-1 are surely coprime hence Phi(n)=n-1:
//For n^x we can say the only factors are n,2n,3n.....n*n,......n*n(x times) hence Phi(n^x)=n^x-n^(x-1)
//Also Phi(x*y) = Phi(x) * Phi(y) given gcd(x,y)=1: same way chose nc1 and kc1 overall (n)(k)
//Now Applying the formula after breaking into prime factors we have a simplified form: taking common from those we get the formula:
// Phi(x) = x*(P1-1)/P1 * (P2-1)/P2 .......



//Novice:  

int Phi(int n){
	int cnt =0;
	for(int i=2;i<n;++i){
		if(gcd(n,i)==1)cnt++;
	}
	return cnt;
}

// Advanced:

int Phi(int n){
	int ans = n;
for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
        ans /= i;
        ans *= (i - 1);
        while(n % i == 0)
            n /= i;
    }
}
if(n > 1){ 
    ans /= n;
    ans *= (n - 1);
}
return ans;

}