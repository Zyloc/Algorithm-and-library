/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAXLENGTH = 1e3+1;
const int MOD = 1e9+7;
int dp[MAXLENGTH],minNumber[MAXLENGTH];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,maxLength(0);
	cin>>n;
	string s;
	cin>>s;
	map<char,lli> maxFreq;
	for(char c='a';c<='z';c++){
		cin>>x;
		maxFreq[c] = x;
	}
	s = '#'+s;
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		minNumber[i] = 1e9;
		map<char,lli> addChar;
		for(int j=i;j>0;j--){
			addChar[s[j]]++;
			bool flag(false);
			for(auto x:addChar){
				if((i-j+1) > maxFreq[x.first]){
					flag = true;
					break;
				}
			}
			if(!flag){
				dp[i] = (dp[i]+dp[j-1])%MOD;
				minNumber[i] = min(minNumber[i],1+minNumber[j-1]);
				maxLength = max(maxLength,(lli)(i-j+1));	
			}
			else{
				break;
			}
		}
	}	
	cout<<dp[n]<<endl;
	cout<<maxLength<<endl;
	cout<<minNumber[n]<<endl;
	return 0;
}