/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<vector<lli> > preProcessed;
bool check2(lli matrix[4][4],lli i,lli j){
	if(matrix[i][j] == matrix[i][j+1] or matrix[i][j] == matrix[i+1][j] or matrix[i][j+1]==matrix[i+1][j+1]){
		return false;
	}
	return true;
}
void magicBox(lli matrix[4][4],lli i,lli j){
	if(i == 3 and j==3){
		if(check2(matrix,0,0) and check2(matrix,0,2) and check2(matrix,2,0) and check2(matrix,2,2) and checck4(matrix,0,0)){
			vector<lli> dummy;
			for(int x(0);x<=3;x++){
				for(int y(0);y<=3;y++){
					dummy.push_back(matrix[x][y]);
				}
			}
			preProcessed.push_back(dummy);
		}
	}
	lli nextI(j==3?i+1:i),nextJ(j==3?0:j+1);
	for(int put(1);put<=3;put++){
		magicBox(nextI,nextJ,put);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	return 0;
}
