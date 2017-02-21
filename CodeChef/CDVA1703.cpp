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
		cin>>n>>x;
		if(n%x){
			cout<<n%x<<endl;
		}
		else{
			cout<<x<<endl;
		}
	}
	return 0;
}