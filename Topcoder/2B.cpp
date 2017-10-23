/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e3+2);
lli input[MAX][MAX],initZero[MAX][MAX];
lli dp[MAX][MAX];
lli n,x;
lli magicBox(lli zeroesSoFar,lli lastDigit,lli row,lli column){
	if(row == n-1 and column == n-1){
		dp[row][column] = min(dp[row][column],zeroesSoFar);
		return dp[row][column];
	}
	lli &ret(dp[row][column]);
	if(ret != INT_MAX){
		dp[row][column];
	}
	lli right(0),down(0);
	if(row < n-1){
		right = magicBox(zeroesSoFar+((input[row+1][column]*lastDigit)%10== 0?1:0),input[row+1][column]*lastDigit%10,row+1,column);
	}
	if(column < n-1){
		down == magicBox(zeroesSoFar+((input[row][column+1]*lastDigit)%10== 0?1:0),input[row][column+1]*lastDigit%10,row,column+1);
	}
	dp[row][column] = min(right,column);
	return dp[row][column];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i(0);i<n;i++){
		for(int j(0);j<n;j++){
			dp[i][j] = INT_MAX;
			cin>>x;
			while(x%10!=0){
				x/=10;
				initZero[i][j]++;
			}
			input[i][j] = x%10;
		}
	}
	magicBox(initZero[0][0],input[0][0],0,0);
	cout<<dp[0][0]<<endl;
	return 0;
}	