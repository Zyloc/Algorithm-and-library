/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
string dummy;
int dp[51][51];
int magicBox(){
	for(int length(2);length<=dummy.length();length++){
		for(int start=0;start<dummy.length();start++){
			int lastIndex(start+length-1);
			dp[start][lastIndex] = min(dp[start+1][lastIndex-1]+(dummy[start]==dummy[lastIndex]?0:1),min(dp[start+1][lastIndex]+1,dp[start][lastIndex-1]+1));
		}
	}
	return dp[0][dummy.length()-1];
}
class PalindromeFactory{
public:
	int getEditDistance(string initial){
		int ans(INT_MAX);
		dummy = initial;
		ans = min(ans,magicBox());
		for(int i=0;i<initial.length();i++){
			for(int j=i+1;j<initial.length();j++){
				dummy = initial;
				swap(dummy[i],dummy[j]);
				memset(dp,0,sizeof dp);
				ans = min(ans,magicBox()+1);
			}
		}
		return ans;
	}
};
