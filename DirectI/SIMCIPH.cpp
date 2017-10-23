/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli getCountSetBits(lli n){
	int count(0);
	for(int i(0);i<=25;i++){
		if((1LL<<i)&n){
			count++;
		}
	}
	return count;
}
lli getFactorial(lli n){
	if(n <= 1){
		return 1;
	}
	return n*getFactorial(n-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		string s[n];
		map<char,lli> mp;
		lli dummy((1LL<<26)-1);
		for(int i(0);i<n;i++){
			cin>>s[i];
			lli temp = 0;
			for(auto x:s[i]){
				if(mp.find(x)==mp.end()){
					mp[x] = dummy;
				}
			}
			for(auto x:s[i]){
				temp |= (1LL<<(x-'A'));
			}
			for(auto x:s[i]){
				mp[x] = mp[x]&temp;
			}
		}
		set<lli> donotCared;
		lli ans(1);
		for(auto x:mp){
			lli value(x.second);
			
			for(auto y:mp){
				for(int i(0);i<26;i++){
					if((y.second)&(1LL<<i)){
						mp[y.first] = mp[y.first]&(~((1LL<<i)-1));
					}
				}
			}
		}
	}
	return 0;
}
