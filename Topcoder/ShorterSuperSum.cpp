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
int dp[15][15];
class ShorterSuperSum{	
public:	
	int calculate(int k,int n){
		if(k==0){
			dp[0][n]=n;
			return dp[0][n];
		}
		for(int i=1;i<n;i++){
			if(dp[k-1][i]==0){
				dp[k-1][i] = calculate(k-1,i);	
			}
			dp[k][n] += dp[k-1][i];
		}
		return dp[k][n];
	}
};
int main(){
	ShorterSuperSum obj;
	cout<<obj.calculate(1,3);
}
