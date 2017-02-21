#include <iostream>
using namespace std;
 
int main() {
	while(1)
	{
	int tot , n;
	cin >> tot >> n;
	if(tot==0 && n==0)
	return 0;
	int ar[n+1] , arr[n+1];
	int dp[n+1][tot+1];
	for(int i=1; i<=n ; i++ )
	{
		cin >> ar[i] >> arr[i];
	}
 
	for(int i=0 ; i<=n ; i++)
	{
		for(int j=0 ; j<=tot ; j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
			}
			else if(ar[i] <= j)
			{
				dp[i][j] = max((arr[i]+dp[i-1][j-ar[i]]) , dp[i-1][j]);
			}
 
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	int r=n , c=tot;
	int ans = 0;
	while(r!=0 && c!=0)
	{
		if(dp[r][c] == dp[r][c-1]){
			c--;
		}
		else{
			break;
		}
	}
	cout << c << " "<< dp[n][tot] <<endl;
}
 
	return 0;
}