/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,q;
const int MAX(1e3+5);
lli BIT[MAX][MAX];
void update(lli x,lli y,lli value){
	for(int i(x);i<=n;i+=(i&-i)){
		for(int j(y);j<=n;j+=(j&-j)){
			BIT[i][j]+=value;
		}
	}
}
lli query(lli x,lli y){
	lli ans(0);
	for(int i(x);i>0;i-=(i&-i)){
		for(int j(y);j>0;j-=(j&-j)){
			ans+=BIT[i][j];
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	lli type,x,y,X,Y,value;
	n+=1;
	while(q--){
		cin>>type;
		if(type == 1){
			cin>>x>>y>>X>>Y;
			cout<<query(X,Y)-query(x-1,Y)+query(X,y-1)+query(x-1,y-1)<<endl;
			//cout<<(query(X,Y)^query(x,y)^query(X,y)^query(x,Y))<<endl;
		}
		else{
			cin>>x>>y>>X>>Y>>value;
			update(x,y,value);
			update(x,Y+1,-value);
			update(X+1,y,-value);
			update(X+1,Y+1,value);
		}
	}
	return 0;
}	