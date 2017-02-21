/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli ans(0);
	lli n,d,x;
	cin>>n>>d;
	vector<lli> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<n;i++){
		lli index(upper_bound(v.begin(),v.end(),v[i]+d)-v.begin()-1);
		if(index-i-1 > 0){
			ans+= ((index-i-1)*(index-i))/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}