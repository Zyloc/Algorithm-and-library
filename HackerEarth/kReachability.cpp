/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(13);
bool prefix[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k,q;
	cin>>n>>k>>q;
	for(int i(1);i<MAX;i++){
	    string from(to_string(n));
	    string to(to_string(i));
	    lli temp(lcs(from,to));
	    if(max(from.size(),to.size())-temp <= k){
	        //cout<<i<<" "<<temp<<endl;
            prefix[i] = 1;
	    }
        prefix[i] += prefix[i-1];
        cout<<prefix[i]<<endl;
	}
    lli l,r;
    for(int i(0);i<q;i++){
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
	return 0;
}	