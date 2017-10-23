/*
*
*
* Whenever you come near me, my mind goes out of memory , my heart goes in 
* dead lock condition. 
* Could you please suggest algorithm to find shortest path to your heart.
*
* 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli fast_expo(lli base, lli expo){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base);
		}
		base=(base*base);
		expo/=2;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	cout<<fast_expo(n,n)<<endl;
	return 0;
}	
