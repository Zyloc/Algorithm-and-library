/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+3);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	set<lli> st;
	lli lastSize(0),ans(-1e18),sum(0);
	for(int i(0);i<n;i++){
		cin>>x;
		st.insert(x);
		if(st.size() != lastSize){
			sum+=x;
			ans = max(ans,max(sum,x));
		}
		lastSize = st.size();
	}
	cout<<ans<<endl;
	return 0;
}	