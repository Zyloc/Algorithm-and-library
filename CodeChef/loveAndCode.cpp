/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli matrix[3][3],dummyMatrix[3][3];
lli identity[3][3];
lli 
lli* solve(lli k){
	if(k == 1){
		return dummyMatrix;
	}
	else if(k%2){
		return multiply(solve(k/2),sum(power(k/2)));
	}
	else{
		return multiply(solve(k/2),sum(power(k/2)))+power(k);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	for(int i=0;i<3;i++){
		identity[i] = 1;
	}
	while(t--){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cin>>matrix[i][j];
				dummyMatrix[i][j] = matrix[i][j];
			}
		}
		lli k;
		solve(k);
	}
	return 0;
}	