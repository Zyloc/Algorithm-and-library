/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli fast_expo(lli base, lli expo){
	lli res=base;
	for(int i=2;i<=expo;i++){
		res = res*base;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli ans(0),sum(0);
		for(int i=1;i<=64;i++){
			lli root(floor(pow(n,(double)1.0/i)));
			if(fast_expo(root,i) == n){
				ans++;
				sum+=root+i;
			}
			if(fast_expo(root+1,i) == n){
				ans++;
					;
			}
		}
		cout<<ans<<endl<<sum<<endl;
	}
	return 0;
}