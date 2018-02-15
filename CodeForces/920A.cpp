/*
 * Richie Rich 
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
		lli n,k;
		cin>>n>>k;
		lli ans(0);
		vector<lli> input(k);
		for(int i(0);i<k;i++){
			cin>>input[i];
		}
		lli time(0);
		bool check[n+1];
		while(true){
			memset(check,false,sizeof check);
			for(int i(0);i<k;i++){
				lli iterator(input[i]);
				while(iterator >= input[i]-time+1 and iterator >= 1){
					check[iterator] = true;
					iterator--;
				}
				iterator = input[i];
				while(iterator<=input[i]+time-1 and iterator <= n){
					check[iterator] = true;
					iterator++;
				}
			}
			bool flag(true);
			for(int i(1);i<=n;i++){
				flag = flag and check[i];
			}
			if(flag){
				cout<<time<<endl;
				break;
			}
			time++;
		}
	}
	return 0;
}
