/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	lli input[n][n];
	for(int i(0);i<n;i++){
		for(int j(0);j<n;j++){
			cin>>input[i][j];
		}
	}
	lli row[n][n],column[n][n];
	for(int i(0);i<n;i++){
		column[0][i] = 1;
		row[i][0] = 1; 
	}
	for(int i(0);i<n;i++){
		for(int j(1);j<n;j++){
			if(input[j][i]>=input[j-1][i]){
				column[j][i] = column[j-1][i]+1;
			}
			else{
				column[j][i] = 1;
			}
		}
	}
	for(int i(0);i<n;i++){
		for(int j(1);j<n;j++){
			if(input[i][j] >= input[i][j-1]){
				row[i][j] = row[i][j-1]+1;
			}
			else{
				row[i][j] = 1;
			}
		}
	}
	lli ans(0);
	for(int i(0);i<n;i++){
		for(int j(0);j<n;j++){
			ans = max(ans,row[i][j]*min(column[i][j],column[i][j-row[i][j]+1]));
		}
	}
	cout<<ans<<endl;
	return 0;
}
