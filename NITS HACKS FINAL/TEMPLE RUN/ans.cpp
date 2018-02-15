/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MOD(1e9+7);

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
lli getChoose(lli n , lli k){
	lli ans(1);
	for(int i(0);i<k;i++){
		ans = ((ans%MOD)*(n-i))%MOD;
		ans = ((ans%MOD)*fast_expo(i+1LL,MOD-2,MOD))%MOD;
	}
	return ans;
}
lli getCatalanNumber(lli n){
	return (getChoose(2*n,n)*fast_expo(n+1,MOD-2,MOD))%MOD;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	cout<<getCatalanNumber(n)<<endl;
	return 0;
}
