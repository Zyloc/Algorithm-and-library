/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m;
	cin>>n>>m;
	int input[n][m];
	for(int i(0);i<n;i++){
		for(int j(0);j<m;j++){
			cin>>input[i][j];
		}
	}
	lli ans(0);
	for(int i(0);i<n;i++){
		ans+=input[i][0];
		ans+=input[i][m-1];
	}
	for(int i(0);i<m;i++){
		ans += input[0][i];
		ans += input[n-1][i];
	}
	for(int i(0);i<m;i++){
		for(int j(1);j<n;j++){
			ans += abs(input[j][i]-input[j-1][i]);
		}
	}
	for(int i(0);i<n;i++){
		for(int j(1);j<m;j++){
			ans += abs(input[i][j]-input[i][j-1]);
		}
	}
	ans+=2*(n*m);
	cout<<ans<<endl;
	return 0;
}
