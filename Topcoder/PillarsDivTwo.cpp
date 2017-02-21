/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
class PillarsDivTwo{
public:
	double maximalLength(vector<int>height, int w){
		double ans(0.0);
		double dp[51][101]={{0}};
		for(int i=0;i<=height[0];i++)
			dp[0][i] = 0.0;
		for(int i=1;i<height.size();i++){
			for(int j=1;j<=height[i];j++){
				for(int k=1;k<height[i-1];k++){
					dp[i][j] = max(dp[i][j],dp[i-1][k]+sqrt(w*w+(j-k)*(j-k)));
					ans = max(ans,dp[i][j]);
				}
			}
		}
		return ans;
	}
};
