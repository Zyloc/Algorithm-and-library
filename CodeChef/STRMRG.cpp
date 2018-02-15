/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli int
using namespace std;
lli n,m;
string a,b;
const int MAX(5e3+2);
lli dp[MAX][MAX][2];
lli magicBox(lli i,lli j,lli front){
	if(i == n and j == m){
		return 0;
	}
	string temp;
	if(i == n or j==m){
		if(front){
			temp = a[i-1];	
		}
		else{
			temp = b[j-1];
		}
		lli count(0);
		if(i == n){
			for(int k(j+1);k<m;k++){
				if(b[k]!=b[k-1]){
					count++;
				}
			}
			if(temp!=to_string(b[j])){
				count++;
			}
		}
		else{
			for(int k(i+1);k<n;k++){
				if(a[k]!=a[k-1]){
					count++;
				}	
			}
			if(temp!=to_string(a[i])){
				count++;
			}
		}
		dp[i][j][front] = count;
		return dp[i][j][front];
	}
	if(dp[i][j][front]!=-1){
		return dp[i][j][front];
	}
	if(front){
		dp[i][j][front] = min(magicBox(i+1,j+1,0)+(a[i]!=a[i+1]?1:0),magicBox(i+1,j+1,1)+(a[i]!=b[j+1]?1:0));
	}
	else{
		dp[i][j][front] = min(magicBox(i+1,j+1,0)+(b[j]!=a[i+1]?1:0),magicBox(i+1,j+1,1)+(b[j]!=b[j+1]?1:0));			
	}
	return dp[i][j][front];
}		
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>a>>b;
		memset(dp,-1,sizeof dp);
		cout<<min(magicBox(0,0,0),magicBox(0,0,1))<<endl;
	}
	return 0;
}
