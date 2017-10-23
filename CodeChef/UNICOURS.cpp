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
		lli n,x,ans(0);
		cin>>n;
		vector<lli> input;
		for(int i(0);i<n;i++){
			cin>>x;
			ans = max(x,ans);
		}
		cout<<n-ans<<endl;
	}
	return 0;
}	
