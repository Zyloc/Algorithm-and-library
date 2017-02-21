/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> prime;
bool IsPrime(lli number){
 
    if (number == 2 || number == 3)
        return true;
 
    if (number % 2 == 0 || number % 3 == 0)
        return false;
 
    lli divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {
 
        if (number % (divisor - 1) == 0)
            return false;

        if (number % (divisor + 1) == 0)
            return false;
 
        divisor += 6;
 
    }
 
    return true;
}
const int MAX = 100000;
bool primes[MAX+1];
void seive(){
	memset(primes,true,sizeof primes);
	for(int i=2;i<=MAX;i++){
		if(primes[i]){
			if(i<1001)
				prime.push_back(i);
			for(int j=2*i;j<=MAX;j+=i){
				primes[j]=false;
			}
		}
	}
}
int main(){
	seive();
	lli ans[1001];
	memset(ans,0,sizeof ans);	
	for(int i=0;i<prime.size();i++){
		int sum(prime[i]);
		for(int j=i+1;j<prime.size();j++){
			sum+=prime[j];
			if(primes[sum]){
				
				ans[prime[i]]++;
			}
		}
	}
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
	}
	return 0;
}