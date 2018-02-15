/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+1);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,x;
		cin>>n;
		vector<lli> odd,even,input;
		vector<pair<lli,lli> > mapper;
		lli freq[MAX];
		memset(freq,0,sizeof freq);
		map<lli,lli> mp;
		for(int i(1);i<=n;i++){
			cin>>x;
			freq[x]++;
			input.push_back(x);
		}
		for(int i(1);i<MAX;i++){
			if(freq[i] == 2){
				even.push_back(i);
			}
		}
		for(int i(0);i+2<=even.size();i+=2){
			mp[even[i]] = even[i+1];
			mp[even[i+1]] = even[i];
		}
		lli shift(1);
		if(even.size()&1){
			odd.push_back(even.back());
			shift++;
		}
		for(int i(1);i<MAX;i++){
			if(freq[i] == 1){
				odd.push_back(i);
			}
		}
		lli remaning(-1);
		if(shift == 2){
			remaning = odd[0];	
		}
		for(int i(0);i<odd.size();i++){
			mp[odd[i]] = odd[(i+shift)%odd.size()];
		}
		bool check(false);
		for(auto x:input){
			if(x == remaning and !check){
				check = true;
				cout<<remaning<<" ";
			}
			else{
				cout<<mp[x]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
