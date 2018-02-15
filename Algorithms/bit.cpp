/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e2+2);
lli n,q,total,change;
int BIT[MAX];
void update(lli index,lli change){
    for(int i(x);i<=n;i+=(i&-i)){
        BIT[i]+=change;
    }
}
lli query(int x,int y,int z){
    lli ans(0);
    for(int i(x);i>0;i-=(i&-i)){
        ans+=BIT[i];
    }
    return ans;
}
/*lli get(lli x,lli y,lli z,lli X,lli Y,lli Z){
    return query(X,Y,Z)-query(x,Y,Z)-query(X,y,Z)-query(X,Y,z)+query(x,y,Z)+query(x,Y,z)+query(X,y,z)-query(x,y,z);
}*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y,z,value,type,X,Y,Z;
	cin>>n>>q;
	vector<lli> input(n+1);
	for(int i(0);i<n;i++){
		cin>>x;
		update(i+1,x);
	}
	for(int i(0);i<q;i++){
		cin>>x>>y;
		cout<<update(i,y)<<endl;
		for(int i(1);i<=n;i++){
			
		}
	}
	return 0;
}	