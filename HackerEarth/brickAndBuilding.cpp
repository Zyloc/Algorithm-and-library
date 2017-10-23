/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+4);
vector<lli> divisors[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli N,Q,x,K;
	for(int i(1);i<MAX;i++){
		for(int j(i);j<MAX;j+=i){
			divisors[j].push_back(i);
		}
	}
	lli counter[MAX];
	memset(counter,0,sizeof counter);
	lli n;
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		for(auto it:divisors[x]){
			counter[it]++;
		}
	}
	lli q;
	cin>>q;
	while(q--){
		cin>>x;
		cout<<counter[x]<<endl;
	}
	return 0;
}
