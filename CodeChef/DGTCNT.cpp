/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli start,upto,maxCountPossible[10]={0};
int check(lli n){
	int hash[10]={0};
	while(n){
		hash[n%10]++;
		n/=10;
	}
	for(int i(0);i<10;i++){
		if(hash[i] == maxCountPossible[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		cin>>start>>upto;
		int ans(0);
		bool zero(true);
		for(int i(0);i<10;i++){
			cin>>maxCountPossible[i];
			if(maxCountPossible[i]!=0){
				zero = false;
			}
		}
		if(!zero){
			for(int i(start);i<=upto;i++){
				ans+= check(i);
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}	