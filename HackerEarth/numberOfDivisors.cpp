/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
const int MOD(1e9+7);
using namespace std;
lli fast_expo(lli base, lli expo,lli MODE){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MODE;
		}
		base=(base*base)%MODE;
		expo/=2;
	}
	return res%MODE;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,sop(1),x;
	cin>>n;
	vector<lli> input;
	for(int i(0);i<n;i++){
	    cin>>x;
	    input.push_back(x);
	    sop = ((sop%MOD)*(x+1)%MOD)%MOD;
	}
	vector<lli> out;
	for(int i(0);i<n;i++){
		lli a(sop%MOD);
		lli b(fast_expo(input[i]+1,MOD-2,MOD)%MOD);
		lli c(input[i]%MOD);
		lli d((input[i]+1LL)%MOD);
	    lli e(fast_expo(2,MOD-2,MOD)%MOD);
	    lli f((a*b)%MOD);
	    lli g((c*d)%MOD);
	    lli j((f*g)%MOD);
	    lli k((e*j)%MOD);
	    out.push_back(k);
	}
	lli ans(1);
	for(auto x:out){
		//cout<<x<<endl;
		ans = ((ans%MOD)*(x+1)%MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}	