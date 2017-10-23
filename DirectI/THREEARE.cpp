/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+5);
int input[3][MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,m,x,y,row;
		cin>>n>>m;
		memset(input,0,sizeof input);
		int sum1(0),sum2(0),sum3(0);
		for(int i(0);i<m;i++){
			cin>>row>>x>>y;
			if(y<x){
				swap(x,y);
			}
			input[row-1][x] += 1;
			input[row-1][y+1] -= 1; 
		}
		lli ans(0);
		lli temp1(0),temp2(0),temp3(0);
		for(int i(1);i<=n;i++){
			sum1+=input[0][i];
			sum2+= input[1][i];
			sum3+= input[2][i];
			if(sum1 == 0){
				temp1 = 0;
			}
			else{
				temp1++;
			}
			
			if(sum2 == 0){
				temp2 = 0;
			}
			else{
				temp2++;
			}
			
			if(sum3 == 0){
				temp3 = 0;
			}
			else{
				temp3++;
			}
			ans = max(ans,min(temp1,min(temp2,temp3))*3);
			ans = max(ans,min(temp1,temp2)*2);
			ans = max(ans,min(temp1,temp3)*2);
			ans = max(ans,min(temp2,temp3)*2);
			ans = max(ans,temp1);
			ans = max(ans,temp2);
			ans = max(ans,temp3);
		}
		cout<<ans<<endl;
	}
	return 0;
}
