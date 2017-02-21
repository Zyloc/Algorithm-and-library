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
class SRMCards{
public:
	int maxTurns(vector<int> v){
		sort(v.begin(),v.end());
		int ans(0);
		for(int i=0;i<v.size();i++){
			if(v[i]+1 == v[i+1]){
				i++;
			}
            ans++;
		}
		return ans;
	}
};
int main(){
	lli n,x;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.pb(x);
	}
	SRMCards obj;
	cout<<obj.maxTurns(v);
}