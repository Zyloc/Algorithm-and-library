#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define MOD 1000000007
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
	lli base,expo;
	cin>>base>>expo;
	cout<<fast_expo(base,expo);
	return 0;
}