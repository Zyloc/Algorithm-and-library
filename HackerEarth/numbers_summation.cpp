/*
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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,sum(0);
	cin>>n;
	lli squareRoot(sqrt(n));
	for(lli i(1);i<=sqrt(n);i++){
		lli dummy((n/i)%MOD),dummy2((i+dummy)%MOD);
		lli variableOne(i%MOD);
		lli variableSecond((i+dummy)%MOD);
		lli variableThird((dummy+1-i%MOD+MOD)%MOD);
		sum += ((variableOne*variableSecond)%MOD*variableThird)%MOD;
		//sum += (i*((i+(n/i))%MOD)*(((n/i)%MOD+1-i+MOD)%MOD)%MOD)%MOD; 
	}
	lli squareSum(0);
	squareSum = (squareRoot*(squareRoot+1))%MOD;
	squareSum = (squareSum*(2*squareRoot+1))%MOD;
	squareSum = (squareSum*fast_expo(6,MOD-2,MOD))%MOD;
	//squareSum = ((((((squareRoot%MOD)*(squareRoot+1))%MOD)*(2*squareRoot+1))%MOD)/6)%MOD; 
	cout<<(sum-squareSum+MOD)%MOD<<endl;	
	return 0;
}	