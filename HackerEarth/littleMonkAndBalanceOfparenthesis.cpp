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
	lli n,x,ans(0),validSubarray(0);
	cin>>n;
	vector<lli> v;
	for(lli i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	stack<lli> st;	
	for(lli i=0;i<n;i++){
		if(v[i] > 0){
			st.push(v[i]);
		}
		else{
			if(!st.empty() and abs(v[i]) == st.top()){
				st.pop();
				validSubarray += 2;
			}
			else{
				ans = max(ans,validSubarray);
				validSubarray = 0;
			}
		}
	}
	if(st.empty()){
		ans = max(ans,validSubarray); 
	}
	cout<<ans<<endl;
	return 0;
}	