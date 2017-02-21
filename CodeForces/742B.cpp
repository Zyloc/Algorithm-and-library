/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
int main(){			
	lli n,x,y,ans(0);
	map<lli,lli> mp;
	cin>>n>>x;
	for(lli i=0;i<n;i++){
		cin>>y;
		lli search(y^x);
		ans += mp[search];
		mp[y]++;
	}
	cout<<ans;
	return 0;
}
