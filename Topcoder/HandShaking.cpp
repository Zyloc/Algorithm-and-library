/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
class HandsShaking{
public:
	long long countPerfect(int n){
		long long dp[n+1];
		dp[2]=1;
		dp[0] = 0;
		dp[4] = 2;
		for(int i=6;i<=n;i+=2){
			dp[i] = dp[i-2]+(dp[4]*dp[i-4])*(i-2)/2;
		}
		return dp[n];
	}
};
