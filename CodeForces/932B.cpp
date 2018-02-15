/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli int
using namespace std;
const int MAX = 1e6+5;
vector<lli> answer[MAX]; 
lli get(lli n){
	if(n < 10){
		return n;
	}
	lli pro(1);
	while(n){
		if(n%10){
			pro *= n%10;
		}
		n/=10;
	}
	return get(pro);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int j(0);j<10;j++){
			answer[0].push_back(0);
		}
	for(int i(1);i<MAX;i++){
		for(int j(0);j<10;j++){
			answer[i].push_back(0);
		}
		lli value(get(i));
		answer[i][value]++;
		for(int j(0);j<10;j++){
			answer[i][j]+=answer[i-1][j];
		}
	}
	lli q,l,r,k;
	cin>>q;
	while(q--){
		cin>>l>>r>>k;
		cout<<answer[r][k]-answer[l-1][k]<<endl;
	}
	return 0;
}
