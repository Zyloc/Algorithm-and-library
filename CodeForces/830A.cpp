/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX_ROW(1e3+5);
const int MAX_COL(2e3+5);
lli dp[MAX_ROW][MAX_COL];
vector<lli> person,key;
lli n,k,p,x;
lli getCost(lli personIndex,lli keyIndex){
	return abs(key[keyIndex]-person[personIndex])+abs(p-key[keyIndex]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k>>p;
	for(int i(0);i<n;i++){
		cin>>x;
		person.push_back(x);
	}
	sort(person.begin(),person.end());
	for(int i(0);i<k;i++){
		cin>>x;
		key.push_back(x);
	}
	sort(key.begin(),key.end());
	for(int i(0);i<=n;i++){
		for(int j(0);j<=k;j++){
			if(i == 0){
				dp[i][j] = 0;
			}
			else if(j < i){
				dp[i][j] = 2e9;
			}
			else{
				dp[i][j] = min(dp[i][j-1],max(dp[i-1][j-1],getCost(i-1,j-1)));
			}
			
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}
