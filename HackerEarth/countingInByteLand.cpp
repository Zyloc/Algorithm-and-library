/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e2+2);
lli n,q,total,change;
int BIT[MAX][MAX][MAX];
void update(int x,int y,int z,lli change){
    for(int i(x);i<=n;i+=(i&-i)){
        for(int j(y);j<=n;j+=(j&-j)){
            for(int k(z);k<=n;k+=(k&-k)){
                BIT[i][j][k]+=change;
            }
        }
    }
}
lli query(int x,int y,int z){
    lli ans(0);
    for(int i(x);i>0;i-=(i&-i)){
        for(int j(y);j>0;j-=(j&-j)){
            for(int k(z);k>0;k-=(k&-k)){
                ans+=BIT[i][j][k];
            }
        }
    }
    return ans;
}
lli get(lli x,lli y,lli z,lli X,lli Y,lli Z){
    return query(X,Y,Z)-query(x,Y,Z)-query(X,y,Z)-query(X,Y,z)+query(x,y,Z)+query(x,Y,z)+query(X,y,z)-query(x,y,z);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y,z,value,type,X,Y,Z;
	cin>>n>>q;
	n+=1;
	while(q--){
	    cin>>type;
	    if(type == 1){
	        cin>>x>>y>>z>>value;
	        total+=value;
	        update(x+1,y+1,z+1,value);
	    }
	    else{
	        cin>>x>>y>>z>>X>>Y>>Z;
	        cout<<total-get(x,y,z,X+1,Y+1,Z+1)<<endl;
	    }
	}
	return 0;
}	