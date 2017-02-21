/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
class ColorfulRoad{
public:
	 int getMin(string road){
		int n = road.length();
		int dp[n];
		dp[n-1] = 0;
		map<char,char> next;
		next['R']='G';
		next['G']='B';
		next['B']='R';
		const int INF = 1e9+7;
		for(int i=n-2;i>=0;i--){
			dp[i] = INF;
			for(int j=i+1;j<n;j++){
				if(road[j]==next[road[i]]){
					dp[i] = min(dp[i],(j-i)*(j-i)+dp[j]);
				}
			}
		} 
		return (dp[0]==INF?-1:dp[0]);
	}
};
