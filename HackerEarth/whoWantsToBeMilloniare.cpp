/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1001;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double dp[MAX];
	dp[0] = 0.0;
	dp[1] = 1.0;
	dp[2] = 0.5;
	for(int i=3;i<MAX;i++){
	    double copyI(i);
	    dp[i] = ;
	}
	lli t;
	cin>>t;
	while(t--){
	    lli x;
	    cin>>x;
	    cout<<dp[x]<<endl;
	}
	return 0;
}