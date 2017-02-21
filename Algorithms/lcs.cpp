/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
lli longestCommonSubSequence(string s1,string s2){
	lli lcs[s1.length()+1][s2.length()+1],ans(0);
	memset(lcs,0,sizeof lcs);
	for(lli i=1;i<=s1.length();i++){
		for(lli j=1;j<=s2.length();j++){
			if(s1[i-1] == s2[j-1]){
				lcs[i][j] = 1 + lcs[i-1][j-1];
			}
			else{
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]); 
			}
			ans = max(ans,lcs[i][j]);
		}
	}
	return ans;
}
int main(){	
	string s1,s2;
	cin>>s1>>s2;
	cout<<longestCommonSubSequence(s1,s2);	
	return 0;
}	