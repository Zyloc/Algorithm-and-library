/*
 * 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
string n;
lli ans,k;
const int MOD(1e9+7);
const int MAX(1e3+2);
lli dp[MAX][2];
lli magicBox(int index,int count,int flag){
	if(index == n.size()){
		return count <= 6;
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	memset(dp,-1,sizeof dp);
	if(k == 6){
		cout<<0<<endl;
	}
	else{

	}
	return 0;
}
