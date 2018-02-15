#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define MOD 1000000007
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
	lli base,expo;
	cout<<((3*fast_expo(2,MOD-2,MOD))%MOD*9)%MOD<<endl;
	return 0;
}