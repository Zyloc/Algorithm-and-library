/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
class ChangingSounds{
public:
	int maxFinal(vector<int> changeIntervals, int beginLevel, int maxLevel){
		lli size(changeIntervals.size());
		lli dp[size+1][2];
		memset(dp,-1,sizeof dp);
		dp[0][0] = beginLevel;
		dp[0][1] = beginLevel;
		bool isAddValid(true),isSubValid(true);
		for(lli i=1;i<=size;i++){
			lli lastMax(max(dp[i-1][0],dp[i-1][1])),lastMin(min(dp[i-1][0],dp[i-1][1]));
			if(not (isAddValid or isSubValid)){
				return -1;
			}
			if(isAddValid){
				if(lastMax + changeIntervals[i-1] <= maxLevel){
					dp[i][0] = lastMax + changeIntervals[i-1];
				}
				else if(lastMin + changeIntervals[i-1] <= maxLevel){
					dp[i][0] = lastMin + changeIntervals[i-1];
				}
				else{
					isAddValid = false;
				}	
			}
			if(isSubValid){
				if(lastMax - changeIntervals[i-1] >= 0){
					dp[i][1] = lastMax - changeIntervals[i-1];
				}
				else{
					isSubValid = false;
				}	
			}
		}
		return max(dp[size][0],dp[size][1]);
	}
};
/*int main(){
	lli n,x,begin,maxi;
	cin>>n;
	vector<int> v;
	for(lli i=0;i<n;i++){
		cin>>x;
		v.pb(x);
	}
	cin>>begin>>maxi;
	ChangingSounds obj;
	cout<<obj.maxFinal(v,begin,maxi)<<endl;
} */
