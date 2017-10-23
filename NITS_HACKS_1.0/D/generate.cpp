/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t,MOD(1e5);
	cin>>t;
	cout<<t<<endl;
	while(t--){
		string first,second;
		for(int i(0);i<1;i++){
			first+= to_string(1+rand()%9);
		}
		for(int i(0);i<17;i++){
			second+= to_string(1+rand()%9);
		}
		cout<<first<<" "<<second<<endl;
		//cout<<min(first,second)<<" "<<max(first,second)<<endl;
	}
	return 0;
}
