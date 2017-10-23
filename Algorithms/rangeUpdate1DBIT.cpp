/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const lli MAX(1e5+5);
lli BIT1[MAX],BIT2[MAX],input[MAX];
lli n,q;
void update(lli *BIT,lli index,lli value){
	for(;index <= n;index+=(index & -index)){
		BIT[index]+=value;
	}
}
lli query(lli *BIT,lli index){
	lli ans(0);
	for(;index > 0;index-=(index & -index)){
		ans+=BIT[index];
	}
	return ans;
}
void rangeUpdate(lli l,lli r,lli value){
	update(BIT1,l,value);
	update(BIT1,r+1,-value);
	update(BIT2,l,value*(l-1));
	update(BIT2,r+1,-value*r);
}
lli getSum(lli index){
	return query(BIT1,index)*index - query(BIT2,index);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,l,r,type,value;
	cin>>n>>q;
	while(q--){
		cin>>type;
		if(type == 1){
			cin>>l>>r>>value;
			rangeUpdate(l,r,value);		
		}
		else{
			cin>>l>>r;
			cout<<getSum(r)-getSum(l-1)<<endl;
		}
	}
	return 0;
}
