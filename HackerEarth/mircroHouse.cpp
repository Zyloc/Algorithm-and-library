/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int row,col;
	cin>>row>>col;
	lli input[row][col],temp[row];
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>input[i][j];
	lli ans(0);
	for(int i=0;i<col;i++){
		memset(temp,0,sizeof temp);
		for(int j=i;j<col;j++){
			for(int z=0;z<row;z++){
				temp[z] ^= input[z][j]; 
			}
			lli maxXorHere(0);
			for(int z=0;z<row;z++){
				maxXorHere = maxXorHere ^ temp[z];
				ans = max(ans,maxXorHere); 
			}
		}
	}
	cout<<ans<<endl;	
	return 0;
}