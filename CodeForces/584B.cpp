/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MOD = 1e9+7;
lli fast_expo(lli base, lli expo){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MOD;
		}
		base=(base*base)%MOD;
		expo/=2;
	}
	return res%MOD;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	cout<<(fast_expo(3,3*n)-fast_expo(7,n)+MOD)%MOD<<endl;
	return 0;
}