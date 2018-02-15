/*
 * Richie Rich 
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
		lli n;
		cin>>n;
		vector<lli> input[5001];
		int l,r;
		for(int i(1);i<=n;i++){
			cin>>l>>r;
			input[l].push_back(i);
			input[r+1].push_back(-i);	
		}
		vector<lli> ans(n+1,0);
		set<lli> st;
		for(int i(1);i<5001;i++){
			for(auto x:input[i]){
				if(x > 0){
					st.insert(x);
				}else{
					if(!st.empty())
						st.erase(-x);
				}
			}
			if(!st.empty()){
				if(*st.begin() > 0){
					lli temp = *st.begin();
					ans[temp] = i;
					st.erase(temp);
					st.erase(-temp);
				}
			}	
		}
		for(int i(1);i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
