/*
 * 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,maxi(-1e18);
	cin>>n;
	map<lli,lli> mp;
	for(int i(0);i<n;i++){
		cin>>x;
		mp[x]++;
		maxi = max(maxi,x);
	}
	if(mp[maxi]&1){
		cout<<"Conan";
	}
	else{
		cout<<"Agasa";
	}
	return 0;
}
