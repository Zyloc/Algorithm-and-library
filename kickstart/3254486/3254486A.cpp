/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
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
	lli t;
	cin>>t;
	for(int i(1);i<=t;i++){
		lli a,b,p;
		cin>>a>>b>>p;
		lli dummy(a%p);
		for(int j(2);j<=b;j++){
			dummy = fast_expo(dummy,j,p)%p;
		}
		cout<<"Case #"<<i<<": "<<dummy<<endl;
	}
	return 0;
}
