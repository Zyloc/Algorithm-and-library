/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
void solve(map<lli,bool> &found,lli x){
    cout<<x<<" ";
    if(found.find(x)!=found.end()){
        //cout<<"NO"<<endl;
       // printf("NO\n");
        return;
    }
    if(x==1 or x==4){
        //cout<<"YES"<<endl;
    //    printf("YES\n");
        return;
    }
    found[x] = true;
    lli sum(0),dummy(x*x);
    while(dummy){
        sum+=dummy%10;
        dummy/=10;
    }
    return solve(found,sum);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	//cin>>t;
	scanf("%lld",&t);
	while(t--){
	    map<lli,bool> found;
	    lli x;
	    //cin>>x;
	    scanf("%lld",&x);
	    cout<<x<<"->";
	    solve(found,x);
	    cout<<endl;
	}
	return 0;
}