#include<bits/stdc++.h>
using namespace std;
int n,m,ar[1<<20];
long long s[1<<20];
long long bst[1<<20];
long long dp[105][2005];
int main(){
ios_base::sync_with_stdio(0);
//cin.tie(0);
cin>>n>>m;
int S=0;
for (int i=1;i<=n;i++)
{
	int sz;
	cin>>sz;
	for (int j=1;j<=sz;j++)
	{
		cin>>ar[j];
		assert(ar[i]>=-1e9&&ar[i]<=1e9);
	}
	for (int j=1;j<=sz;j++)
		s[j]=s[j-1]+ar[j];
	
	for (int j=1;j<=m;j++)
		bst[j]=-1e15;
	
	for (int j=1;j<=sz;j++)
		for (int q=1;q<=m&&q+j-1<=sz;q++)
		{
			bst[q]=max(bst[q],s[j+q-1]-s[j-1]);
		}
	
	bst[0]=0;
	
	for (int j=0;j<=m;j++)
		for (int take=0;take<=m;take++)
			dp[i][j+take]=max(dp[i][j+take],dp[i-1][j]+bst[take]);
}
cout<<dp[n][m]<<endl;
//cin.get();cin.get();
return 0;}