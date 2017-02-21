/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<lli> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	lli minimum(v[0]),maximum(v[n-1]);
	int ans(0);
	for(int i=0;i<n;i++){
		if(v[i] > minimum and v[i] < maximum){
			ans++;
		}
	}
	cout<<ans;
	return 0;
	return 0;
}