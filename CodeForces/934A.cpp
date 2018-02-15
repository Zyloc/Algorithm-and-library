/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,x;
	cin>>n>>m;
	vector<lli> tommy,bann;
	for(int i(0);i<n;i++){
		cin>>x;
		tommy.push_back(x);
	}
	for(int i(0);i<m;i++){
		cin>>x;
		bann.push_back(x);
	}
	vector<lli> ans;
	for(int j(0);j<n;j++){
		lli temp(-1e18);
		for(int k(0);k<m;k++){
			temp = max(temp,tommy[j]*bann[k]);
		}
		ans.push_back(temp);
	}
	sort(ans.begin(),ans.end());
	cout<<ans[ans.size()-2]<<endl;
	return 0;
}