/*
 * Richie who's not Rich 
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
		pair<lli,lli> a,b,temp,a1,b1;
		cin>>a.first>>a.second>>b.first>>b.second;
		if(a.second > b.second){
			a1 = {a.first,b.second};
			b1 = {b.first,a.second};
			a = a1;
			b = b1;
		}
		lli n,ans(0);
		cin>>n;
		while(n--){
			cin>>temp.first>>temp.second;
			if(temp.first > a.first and temp.first < b.first and temp.second > a.second and temp.second < b.second){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
