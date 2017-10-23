/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,m,k;
lli magicBox(lli *dp,lli n,lli left){
	if(left == 0){
		return (n==0?1:0);
	}
	if(*((dp+n*((n-1)/k+1))+left) != -1){
		return (*((dp+n*((n-1)/k+1))+left));
	}
	*((dp+n*((n-1)/k+1))+left) = 0;
	for(int i(1);i<=min(n,k);i++){
		*((dp+n*((n-1)/k+1))+left) += magicBox(dp,n-i,left-1)%m;
	}
	//cout<<(*((dp+n*((n-1)/k+1))+left))<<endl;
	return *((dp+n*((n-1)/k+1))+left);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		cin>>n>>k>>m;
		lli dp[n+1][k+1];
		memset(dp,-1,sizeof dp);
		cout<<(n-1)/k+1<<" "<<magicBox((lli *)dp,n,(n-1)/k+1)%m<<endl;
	}
	return 0;
}