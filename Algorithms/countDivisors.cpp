/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e6+1;
bool isPrime[MAX];
vector<lli> primeNumber;
const int MOD = 1e9+7
lli fast_expo(lli base, lli expo){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MOD;
		}
		base=(base*base)%MOD;
		expo/=2;
	}
	return res%MOD;
}
void seive(){
	for(int i=2;i<MAX;i++){
		if(!isPrime[i]){
			primeNumber.push_back(i);
			for(int j=2*i;j<MAX;j+=i){
				isPrime[j]=  true;
			}
		}
	}
}
lli countDivisors(lli n){
	lli ans(1);
	for(auto p:primeNumber){
		if(p*p*p > n){
			break;
		}
		lli count(1);
		while(n%p == 0){
			count++;
		}
		ans = ans*count;
	}
	int squareRoot(sqrt(n));
	if(binary_search(primeNumber.begin(),primeNumber.end(),n)){
		ans = ans*2;
	}
	else if(squareRoot * squareRoot == n and binary_search(primeNumber.begin(),primeNumber.end(),squareRoot)){
		ans = ans*3;
	}
	else if (n!=1){
		ans = ans*4;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}