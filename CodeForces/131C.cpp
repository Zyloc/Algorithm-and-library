/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX  = 61;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli choose[MAX][MAX];
	for(int i=0;i<MAX;i++){
		for(int j=0;j<=i;j++){
			if(j==0 or j==i){
				choose[i][j] = 1;
			}
			else{
				choose[i][j] = choose[i-1][j]+choose[i-1][j-1];	
			}
		}
	}
	lli n,m,t;
	cin>>n>>m>>t;
	lli ans(0);
	for(int i=4;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i+j == t){
				ans += choose[n][i]*choose[m][j];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}