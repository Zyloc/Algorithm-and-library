/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		string s,hackerRank("hackerrank");
		cin>>s;
		int LCS[s.length()+1][hackerRank.length()+1];
		for(int i=0;i<=s.length();i++){
			for(int j=0;j<=hackerRank.length();j++){
				if(i == 0 or j==0){
					LCS[i][j] = 0;
				}
				else if(s[i] == hackerRank[j]){
					LCS[i][j] = 1+LCS[i-1][j-1];
				}
				else{
					LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
				}
			}
		}
		if(LCS[s.length()][hackerRank.length()] == 10){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}