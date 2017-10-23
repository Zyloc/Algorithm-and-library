/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,m,q;
int dp[((1<<20)+5)];
bool isValid(string checkVector[],lli i,lli j){
	if(i!=0 and checkVector[i-1][j] == '0'){
		return true;
	}
	if(j!=0 and checkVector[i][j-1] == '0'){
		return true;
	}
	if(i!=n-1 and checkVector[i+1][j] == '0'){
		return true;
	}
	if(j!=m-1 and checkVector[i][j+1] == '0'){
		return true;
	}
	return false;
}
int key(string checkVector[]){
	int sum(0);
	for(int i(0);i<n;i++){
		for(auto x:checkVector[i]){
			sum = sum*2+(x-'0');
		}
	}
	return sum;
}
int magicBox(string checkVector[]){
	int genratedKey(key(checkVector));
	if(dp[genratedKey]!=-1){
		return dp[genratedKey];
	}
	bool flag(0);
	for(int i(0);i<n;i++){
		for(int j(0);j<m;j++){
			if (checkVector[i][j] == '0' and isValid(checkVector,i,j)){
				checkVector[i][j] = '1';
				if(!magicBox(checkVector)){
					flag = 1;
				}
				checkVector[i][j] = '0';
			}
		}	
	}
	dp[genratedKey] = flag;
	return flag;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>q;
	string s[n];
	while(q--){
		for(int i=0;i<n;i++){
			cin>>s[i];	
		}
		cout<<1-magicBox(s)<<endl;
	}
	return 0;
}	