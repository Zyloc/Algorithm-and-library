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
	zyloc(){
		lli n,x;
		cin>>n;
		map<lli,lli> mp;
		for (int i = 0; i < n; ++i){
			cin>>x;
			mp[x]++;
		}
		auto it=mp.begin();
		cout<<(it.second&1:"Lucky":"Unlucky")<<endl;
	}
	return 0;
}	