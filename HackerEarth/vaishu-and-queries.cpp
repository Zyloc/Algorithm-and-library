/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli dp[105][105][105];
lli n,q;
vector<pair<lli,lli> > countOfBalls;
lli magicBox(lli index,lli red,lli blue){
	if(index == n){
		return 0;
	}
	if(dp[red][blue][index]!=-1){
		return dp[red][blue][index];
	}
	dp[red][blue][index] = magicBox(index+1,red,blue);
	if(red >=  countOfBalls[index].first and blue >= countOfBalls[index].second){
		dp[red][blue][index] = max(dp[red][blue][index],1+magicBox(index+1,red-countOfBalls[index].first,blue-countOfBalls[index].second));
	}
	return dp[red][blue][index];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	string input;
	for(int i(0);i<n;i++){
		cin>>input;
		countOfBalls.push_back({0,0});
		for(auto x:input){
			if(x == 'R'){
				countOfBalls[i].first += 1; 
			}
			else{
				countOfBalls[i].second += 1; 	
			}
		}
	}
	memset(dp,-1,sizeof dp);
	cin>>q;
	while(q--){
		lli red,blue;
		cin>>red>>blue;
		cout<<magicBox(0,red,blue)<<endl;
	}
	return 0;
}	