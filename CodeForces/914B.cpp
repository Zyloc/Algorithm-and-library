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
	vector<lli> input;
	for(int i(0);i<n;i++){
		cin>>x;
		mp[x]++;
		maxi = max(maxi,x);
		if(mp[x] == 1){
			input.push_back(x);	
		}
	}
	sort(input.rbegin(),input.rend());
	for(int i(0);i<input.size();i++){
		if(mp[input[i]]&1){
			cout<<"Conan";
			return 0;
		}
	}
	cout<<"Agasa"<<endl;
	return 0;
}
