/*
 * Keep breathing :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e3+1);
int dp[MAX][MAX][14];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<pair<lli,lli> > input;
	memset(dp,-1,sizeof dp);
	for(int i(0);i<n;i++){
		for(int j(0);j<n;j++){
			cin>>x;
			lli powerOfTwo(0),powerOfFive(0);
			while(x%2 == 0){
				powerOfTwo++;
				x/=2;
			}
			while(x%5 == 0){
				powerOfFive++;
				x/=5;
			}
			dp[i][j][powerOfFive] = powerOfTwo;
			input.push_back({powerOfTwo,powerOfFive});
		}
	}
	for(int i(0);i<n;i++){
		for(int j(0);j<n;j++){
			for(int k(0);k<14;k++){
				if(dp[i][j][k]!=-1){

				}
			}
		}
	}
	return 0;
}
