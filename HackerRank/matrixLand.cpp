/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli int
using namespace std;
lli n,m;
void solve(vector<vector<lli> > &input,vector<vector<lli> > &minLeftIndex,vector<vector<lli> > &maxRightIndex,vector<vector<lli> > &prefixSum,vector<vector<lli> > &ans,lli x,lli y){
	if(x == n-1){
		if(y!=0){
			return prefixSum[n-1][m-1]-prefixSum[n-1][y-1];
		}
		return prefixSum[n-1][m-1];
	}
	
}																																																																																																																																																																																																																														
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	vector<vector<lli> > input(n,vector<lli>(m,0));
	vector<vector<lli> > minLeftIndex(n,vector<lli>(m,0));
	vector<vector<lli> > maxRightIndex(n,vector<lli>(m,0));
	vector<vector<lli> > ans(n,vector<lli>(m,INT_MAX					));
	vector<vector<lli> > prefixSum(n,vector<lli>(m,0));
	for(int i(0);i<n;i++){
		for(int j(0);j<m;j++){
			ans[i][j] = INT_MAX;
			cin>>input[i][j];
			if(j!=0){
				prefixSum[i][j] = prefixSum[i][j-1]+input[i][j];
			}
			else{
				prefixSum[i][j] = input[i][j];
			}
		}
	}
	for(int i(0);i<n;i++){
		maxRightIndex[i][m-1] = m-1;
		for(int j(m-2);j>=0;j--){
			if(input[i][j]+prefixSum[i][maxRightIndex[i][j+1]]-prefixSum[i][j] >= 0){
				maxRightIndex[i][j] = maxRightIndex[i][j+1];				
			}
			else{
				maxRightIndex[i][j] = j;
			}
		}
	}
	for(int i(0);i<n;i++){
		minLeftIndex[i][0] = 0;
		for(int j(1);j<m;j++){
			if(input[i][j]+prefixSum[i][minLeftIndex[i][j-1]] >= 0){
				minLeftIndex[i][j] = minLeftIndex[i][j-1];
			}
			else{
				minLeftIndex[i][j] = j;
			}
		}
	}
	for(int i(0);i<m;i++){
		if(ans[0][i] == INT_MAX){
			solve(input,minLeftIndex,maxRightIndex,prefixSum,ans,0,i);
		}
	}
	return 0;
}
