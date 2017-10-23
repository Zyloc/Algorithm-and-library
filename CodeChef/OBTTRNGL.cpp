/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		double k,b,c;
		lli ans(0);
		cin>>k>>b>>c;
		if(abs(b-c)*(360.0/k) > 180.0){
			ans+=k-abs(b-c)-1;
		}
		if((360.0 - abs(b-c)*(360.0/k)) > 180.0){
			ans+=abs(b-c)-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
