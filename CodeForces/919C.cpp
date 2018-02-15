/*
 * Richie Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,k;
	cin>>n>>m>>k;
	lli topDown[n+1][m+1],leftRight[n+1][m+1];
	char input[n+1][m+1];
	memset(topDown,0,sizeof topDown);
	memset(leftRight,0,sizeof leftRight);
	for(int i(0);i<n;i++){
		for(int j(0);j<m;j++){
			cin>>input[i][j];
		}
	}
	for(int i(0);i<n;i++){
		for(int j(0);j<m;j++){
			if(j == 0){
				if(input[i][j] == '.'){
					leftRight[i][j] += 1; 	
				}
			}
			else{
				if(input[i][j] == '.'){
					leftRight[i][j] = leftRight[i][j-1]+1; 	
				}
			}
		}
	}
	for(int j(0);j<m;j++){
		for(int i(0);i<n;i++){
			if(i == 0){
				if(input[i][j] == '.'){
					topDown[i][j] += 1;
				}
			}
			else{
				if(input[i][j] == '.'){
					topDown[i][j] = topDown[i-1][j]+1; 	
				}	
			}
		}
	}
	lli ans(0);
	for(int i(0);i<n;i++){
		for(int j(0);j<m;j++){
			if(leftRight[i][j] >= k){
				ans++;
			}
		}
	}
	for(int j(0);j<m;j++){
		for(int i(0);i<n;i++){
			if(topDown[i][j] >= k){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
