/*
 * Everyting happens for a reason . Hold tight everything is gonna ok :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,k;
	cin>>n>>m>>k;
	lli input[n][m],preColumn[n][m],suffixColm[n][m];
	for(int i(0);i<n;i++){
		for(int j(0);j<m;j++){
			cin>>input[i][j];
		}
	}
	for(int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			if(j!=0){
				preColumn[j][i] = preColumn[j-1][i]+input[j][i];
			}
			else{
				preColumn[j][i] = input[j][i];
			}
		}
	}
	for(int j(0);j<m;j++){
		for(int i(n-1);i>=0;i--){
			if(i!=n-1){
				suffixColm[i][j] = suffixColm[i+1][j]+input[i][j];
			}
			else{
				suffixColm[i][j] = input[i][j];
			}
		}
	}
	lli ans(0),counter(0);
	for(int j(0);j<m;j++){
		lli tempAns(0),tempCounter(0);
		for(int i(0);i<n;i++){
			lli upZero(0);
			if(i != 0){
				upZero = preColumn[i-1][j];
			}
			if(upZero == 0){
				if(i!=0){
					tempAns = max(tempAns,preColumn[min(i+k-1,n-1)][j]-preColumn[i-1][j]);	
				}
				else{
					tempAns = max(tempAns,preColumn[min(i+k-1,n-1)][j]);
				}
			}
			else{
				if(preColumn[min(i+k-1,n-1)][j]-preColumn[i-1][j] > tempAns){
					tempAns = preColumn[min(i+k-1,n-1)][j]-preColumn[i-1][j];
					tempCounter = preColumn[i-1][j];
				}
			}
		}
		ans += tempAns;
		counter += tempCounter;
	}
	cout<<ans<<" "<<counter<<endl;
	return 0;
}
