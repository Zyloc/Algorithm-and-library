/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
const int MOD = 1e9+7;
using namespace std;
class VocaloidsAndSongs{
public:
	int dp[51][51][51][51];
	int magicBox(int S,int a,int b,int c){
		if(S == 0){
			if(a+b+c == 0){
				return 1;
			}
			return 0;
		}
		if(S > a+b+c){
			return 0;
		}
		int &ret = dp[S][a][b][c];
		if(ret!=-1){
			return ret;
		}
		ret = 0;
		if(a) ret = (ret+magicBox(S-1,a-1,b,c))%MOD;
		if(b) ret = (ret+magicBox(S-1,a,b-1,c))%MOD;
		if(c) ret = (ret + magicBox(S-1,a,b,c-1))%MOD;
		if(a && b) ret = (ret + magicBox(S-1,a-1,b-1,c))%MOD;
		if(a && c) ret = (ret + magicBox(S-1,a-1,b,c-1))%MOD;
		if(b && c) ret = (ret + magicBox(S-1,a,b-1,c-1))%MOD;
		if(a && b && c) ret = (ret + magicBox(S-1,a-1,b-1,c-1))%MOD;
		return ret%MOD;
	}
	int count(int S, int a, int b, int c){
		memset(dp,-1,sizeof dp);
		return magicBox(S,a,b,c);
		return 0;
	}
};
