/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		lli input[n],positive[n+1],negative[n+1];
		positive[0] = 0;
		negative[n] = 0;
		for(int i(0);i<n;i++){
			cin>>input[i];
			if(input[i] == 1){
				positive[i] = 1 + positive[max(i-1,0)];
			}
			else{
				positive[i] = positive[max(i-1,0)];
			}
		}
		for(int i(n-1);i>=0;i--){
			if(input[i] == -1){
				negative[i] = 1 + negative[i+1];
			}
			else{
				negative[i] = negative[i+1];
			}
		}
		lli cost(INT_MAX);
		for(int i(0);i<n-2;i++){
			cost = min(cost,positive[i]+negative[i+1]);
		}
		if(input[n-1] == 1){
			cost = min(cost,positive[n-2]);
		}
		else{
			cost = min(cost,1+positive[n-2]);	
		}
		if(input[0] == -1){
			cost = min(cost,negative[1]);
		}
		else{
			cost = min(cost,1+negative[1]);
		}
		cout<<cost<<endl;
	}
	return 0;
}	