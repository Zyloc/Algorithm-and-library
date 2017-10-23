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
		lli n,x;
		cin>>n;
		bool flag(false);
		int MAX;
		cin>>MAX;
		for(int i=1;i<n;i++){
			cin>>x;
			if(x >= MAX){
				flag = true;
			}
			MAX = x;
		}
		if(flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}	