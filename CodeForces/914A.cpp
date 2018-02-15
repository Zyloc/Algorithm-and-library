/*
 * 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,ans(-1e18);
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		if(int(sqrt(x)) * int(sqrt(x)) != x){
			ans = max(ans,x);
		}
	}
	cout<<ans<<endl;
	return 0;
}
