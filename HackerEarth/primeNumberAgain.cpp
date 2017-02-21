/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 10001;
bool prime[MAX];
vector<lli> primes;
int dp[MAX];
void seive(){
	dp[0] = INT_MAX;
	dp[1] = INT_MAX;
    for(int i=2;i<MAX;i++){
        dp[i] = INT_MAX;
        if(!prime[i]){
        	primes.push_back(i);
            for(int j=2*i;j<MAX;j+=i){
                prime[j] = true;
            }
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	seive();
	primes.push_back(4);
	primes.push_back(27);
	primes.push_back(256);
	primes.push_back(3125);
	sort(primes.begin(),primes.end());
	for(int i=2;i<MAX;i++){
	    if(binary_search(primes.begin(),primes.end(),i)){
	    	dp[i] = 1;
	    }
	    else{
	    	for(int j=0;primes[j]<=i;j++){
	    		if(dp[i-primes[j]]!=INT_MAX){
	    			dp[i] = min(dp[i],1+dp[i-primes[j]]);	
	    		}
	    	}	
	    }
	}
	lli t;
	cin>>t;
	while(t--){
	    lli n;
	    cin>>n;
	    cout<<dp[n]<<endl;
	}
	return 0;
}