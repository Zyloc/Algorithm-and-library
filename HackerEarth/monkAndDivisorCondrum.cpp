/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 200001;
const lli MOD = 1000000007;
lli freq[MAX];
lli ans[MAX];
void seive(){
	for (lli i=2;i<MAX;i++){
		for(lli j=i;j<MAX;j=j+i){
			ans[i] += freq[j]; 
		}
	}
}
lli lcm(lli x,lli y){
	return (x*y)/__gcd(x,y);
}
int main(){			
	lli x,n,t,y;
	cin>>n;
	for(lli i=0;i<n;i++){
		cin>>x;
		freq[x]++;
	}
	ans[1] = n;
	seive();
	cin>>t;
	for(lli i=0;i<t;i++){
		cin>>x>>y;
		if(lcm(x,y)<MAX){
			cout<<ans[y]+ans[x]-ans[lcm(x,y)]<<endl;
		}
		else{
			cout<<ans[x]+ans[y]<<endl;
		}
		 
	}
	return 0;
}
