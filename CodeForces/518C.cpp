/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(2222);
double dp[MAX][MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,t;
	double p,expected(0);
	cin>>n>>p>>t;
	dp[0][0] = 1.0;
	for(int time(0);time<t;time++){
		for(int person(0);person<n;person++){
			dp[time+1][person] += (1.0-p)*dp[time][person];
			dp[time+1][person+1] += p*dp[time][person]; 
		}
		dp[time+1][n] += dp[time][n]; 
	}
	for(int i(0);i<=n;i++){
		expected+= dp[t][i]*i;
	}
	cout<<setprecision(9)<<fixed<<expected<<endl;
	return 0;
}	