/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
lli magicBox(lli n,lli k){
	if(n == 1 ){
		if(k==2){
			return 2;
		}
		else{
			return 1;
		}
	}
	else{
		if(k == (1LL<<n)){
			return n+1;
		}
		else if(k > (1LL<<n)){
			return magicBox(n-1,k-(1LL<<n));
		}
		else{
			return magicBox(n-1,k);
		}
	}
}
int main(){	
	lli n,k;
	cin>>n>>k;
	cout<<magicBox(n,k);
	return 0;
}	