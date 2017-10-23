/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+2);
vector<lli> input[MAX];
vector<pair<lli,lli> > dummy;
lli n;
map<pair<lli,lli>,lli> dp;
lli magicBox(lli index,lli lastEndIndex,lli valueSoFar){
	if(index == n-1){
		return valueSoFar;
	}		
	if(dp[{index,lastEndIndex}]!=dp.end()){
		return dp[{index,lastEndIndex}];
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		dp.clear();
		dummy.clear();
		for(int i(0);i<MAX;i++){
			input[i].clear();
		}
		cin>>n;
		for(int i(0);i<n;i++){
			lli m,x;
			cin>>m;
			lli maxi(0),mini(INT_MAX),maxiIndex(0),miniIndex(0);
			for(int j(0);j<m;j++){
				cin>>x;
				input[i].push_back(x);
				if(x > maxi ){
					maxi = x;
					maxiIndex = j;
				}
				if(x < mini){
					mini = x;
					miniIndex = j;
				}
			}
			dummy.push_back({maxiIndex,miniIndex});
		}
		cout<<max(magicBox(n-2,dummy[n-1].first,0),magicBox(n-2,dummy[n-1].second,0))<<endl;
	}
	return 0;
}
