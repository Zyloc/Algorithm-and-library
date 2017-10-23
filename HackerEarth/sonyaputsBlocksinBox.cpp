/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1<<20);
const int MAX_SIZE(105);
int best[MAX];
int dp[105][2005];
int input[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,size;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>size;
		for(int j=1;j<=size;j++){
			cin>>input[j];
			input[j]+=input[j-1];
		}
		for(int j=1;j<=m;j++){
			best[j]= -1e9;
		}
		for(int start=1;start<=size;start++){
			for(int length=1;length<=m and start+length-1<=size;length++){
				best[length] = max(best[length],input[start+length-1]-input[start-1]);
			}
		}
		best[0] = 0;
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m;k++){
				dp[i][j+k] = max(dp[i-1][j+k],best[k]+dp[i-1][j]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}	