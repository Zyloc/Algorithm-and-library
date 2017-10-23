/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<lli,lli> mp;
	lli n,x;
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		mp[x]++;
	}
	auto it=mp.begin();
	auto it2=--mp.end();

	if(mp.size() == 2 and it->second ==it2->second){
		cout<<"YES"<<endl;
		cout<<it->first<<" "<<it2->first<<endl;
	}	
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
