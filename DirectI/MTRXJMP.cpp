/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli int
using namespace std;
int minHops(int matrix[64][64], int m, int n){
	lli dp[64][64];
	for(int i(0);i<64;i++){
		for(int j(0);j<64;j++){
			dp[i][j] =  INT_MAX;
		}	
	}
	dp[0][0] = 1;
	for(int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			int steps(matrix[i][j]);
			if(i+steps < m and dp[i][j]!= INT_MAX){
				dp[i+steps][j] = min(dp[i][j]+1,dp[i+steps][j]);
			}
			if(j+steps < n and dp[i][j]!= INT_MAX){
				dp[i][j+steps] = min(dp[i][j]+1,dp[i][j+steps]);	
			}
		}	
	}
	return dp[m-1][n-1]==INT_MAX?0:dp[m-1][n-1];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli m,n;
	cin>>m>>n;
	lli matrix[64][64];
	for(int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			cin>>matrix[i][j];
		}
	}
	cout<<minHops(matrix,m,n)<<endl;
	return 0;
}
