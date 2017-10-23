/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
class MergeStrings{
public:
	string getmin(string S, string A, string B){
		string dp[51][51][51];
		for(int i=S.length();i>=0;i--){
			for(int j=A.length();j>=0;j--){
				for(int k=B.length();k>=0;k--){
					if(i == S.length()){
						dp[i][j][k] = "";
					}
					else{
						dp[i][j][k] = "{}";
						if(j < A.length() and (S[i] == A[j] or S[i] == '?')){
							string temp(dp[i+1][j+1][k]);
							if(temp != "{}"){
								dp[i][j][k] = min(dp[i][j][k],A[j]+temp);
							}
						}
						if(k < B.length() and (S[i] == B[k] or S[i] == '?')){
							string temp(dp[i+1][j][k+1]);
							if(temp != "{}"){
								dp[i][j][k] = min(dp[i][j][k],B[k]+temp);
							}
						}
					}
				}
			}
		}
		if(dp[0][0][0] == "{}"){
			return string("");
		}
		else{
			return dp[0][0][0];
		}
	}
};
