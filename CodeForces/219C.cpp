/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e5*5+1;
int dp[MAX][26];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	char maxChar('A'+k-1);
	for(int i=0;i<s.length();i++){
		for(int j=0;j<26;j++){
			dp[i][j] = INT_MAX;
		}
		for(char left='A';left<=maxChar;left++){
			for(char middle='A';middle<=maxChar;middle++){
				for(char right='A';right<=maxChar;right++){
					if(middle!=left and middle!=right){
						if(i == 0){
							if(middle == s[0]){
								if(right != s[1]){
									dp[i][middle-'A'] = min(dp[i][middle-'A'],1);
								}
								else{
									dp[i][middle-'A'] = min(dp[i][middle-'A'],0);	
								}
							}
							else{
								if(right != s[1]){
									dp[i][middle-'A'] = min(dp[i][middle-'A'],2);
								}
								else{
									dp[i][middle-'A'] = min(dp[i][middle-'A'],1);
								}
							}
							//cout<<middle<<" "<<right<<" "<<dp[i][middle-'A']<<endl;
						}
						else if(i == s.length()-1){
							if(middle == s[i]){
								dp[i][middle-'A'] = min(dp[i][middle-'A'],dp[i-1][left-'A']);
							}
							else{
								dp[i][middle-'A'] = min(dp[i][middle-'A'],dp[i-1][left-'A']+1);
							}
							//cout<<middle<<" "<<right<<" "<<dp[i][middle-'A']<<endl;
						}
						else{
							//cout<<left<<middle<<right<<endl;
							if(middle == s[i]){
								if(right != s[i+1]){
                                	dp[i][middle-'A'] = min(dp[i][middle-'A'],dp[i-1][left-'A']+1); 
								}
								else{
									//cout<<"ere";
									dp[i][middle-'A'] = min(dp[i][middle-'A'],dp[i-1][left-'A']);
								}
							}
							else{
								if(right != s[i+1]){
                                	dp[i][middle-'A'] = min(dp[i][middle-'A'],dp[i-1][left-'A'] + 2); 
								}
								else{
									dp[i][middle-'A'] = min(dp[i][middle-'A'],dp[i-1][left-'A'] + 1);
								}							
							}
							//cout<<left<<" "<<middle<<" "<<right<<" "<<dp[i][middle-'A']<<endl;
						}
					}	
				}
			}
		}
	}
	int ans(INT_MAX);
	for(int i=0;i<26;i++){
		ans = min(ans,dp[s.length()-1][i]);
	}
	cout<<ans<<endl;
	return 0;
}