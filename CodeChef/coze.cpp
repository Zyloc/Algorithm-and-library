/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX (1e6+5);
lli prefix[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,q,x;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==3  or x==4 or x==6){
			prefix[i]+=1;
		}
		prefix[i]+=prefix[i-1];
	}
	while(q--){
		lli l,r;
		cin>>l>>r;
		cout<<prefix[r]-prefix[l-1]<<endl;
	}
	return 0;
}	