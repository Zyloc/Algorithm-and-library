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
int main(){			
	lli n,ans(1);
	cin>>n;
	if(n==0){
		cout<<1;
	}
	else if(n%4==0){
		cout<<6;
	}
	else if(n%4==1){
		cout<<8;
	}
	else if(n%4==2){
		cout<<4;
	}
	else if(n%4==3){
		cout<<2;
	}
	return 0;
}
