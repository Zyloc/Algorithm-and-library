/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX_LENGTH = 1e6+10;
int dp[MAX_LENGTH];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int ans(0);
	    for(int i=2;i<s.length();i++){
	        if(!(s[i] == s[i-1] and s[i-1] == s[i-2])){
	            dp[i+1] =  1 + dp[i-2];
	        }
	        ans = max(ans,dp[i+1]);
	    }
	    cout<<s.length()-ans*3<<endl;
	    memset(dp,0,sizeof dp);
	}
	return 0;
}