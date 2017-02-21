/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
class RelativelyPrimeSubset{
public:
	 int findSize(vector <int> S){
		vector<int> primes;
		int n(S.size());
		bool prime[51];
		memset(prime,true,sizeof prime);
		for(int i=2;i<51;i++){
			if(prime[i]){
				primes.push_back(i);
				for(int j=2*i;j<51;j+=i){
					prime[j]=false;
				}	
			}
		}
		vector<int> factors;
		for(int i=0;i<(1<<15);i++){
			int mul(1);
			for(int j=0;j<primes.size();j++){
				if(i&(1<<j)){
					mul*=primes[j];
				}
			}
			if(mul!=1){
				factors.push_back(mul);	
			}
		}
		int ans(0);
		for(int i=0;i<factors.size();i++){
			int count(0);
			for(int j=0;j<S.size();j++){
				if(S[j]%factors[i]==0){
					count++;
				}
			}
			ans = max(n-count,ans);
		}
		return ans;
	}
};
int main(){
	vector<int> v = {2,3,7,11,4};
	RelativelyPrimeSubset obj;
	cout<<obj.findSize(v);
	return 0;
}