/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
map<pair<lli,lli>,lli> solved;
const int MOD(1e9+7);
lli magicBox(lli n,lli left){
	if(left == 1){
		return 1;
	}
	if(solved.find({n,left})!=solved.end()){
		return solved[{n,left}];
	}
	lli ans(0);
	for(int i(1);i<=n;i++){
		if(n%i == 0){
			ans = (ans+magicBox(n/i,left-1)%MOD)%MOD;
		}
	}
	solved[{n,left}] = ans;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli q;
	cin>>q;
	lli x,y;
	while(q--){
		cin>>x>>y;
		cout<<magicBox(x,y)<<endl;
	}
	return 0;
}
