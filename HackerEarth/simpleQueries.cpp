/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+2);
int bit[MAX];
void update(lli index,lli value){
	for(int i(index);i<MAX;i+=(i&(-i))){
		bit[i]+=value;
	}
}
lli query(lli index){
	lli ans(0);
	for(int i(index);i>0;i-=(i&(-i))){
		ans+=bit[i];
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,q,x,y;
	string s;
	cin>>n>>s>>q;
	for(int i(0);i<n;i++){
		if(s[i] == '1'){
			update(i+1,1);
		}
	}
	while(q--){
		cin>>x;
		if(x == 1){
			cin>>y;
			if(s[y-1]=='0'){
				update(y,1);
				s[y-1] = '1';
			}
			else{
				update(y,-1);
				s[y-1] = '0';
			}
		}
		else{
			cin>>x>>y;
			lli ans(-10);
			lli left(x),right(y);
			while(left <= right){
				lli mid((left+right)/2);
				if(query(mid)-query(x-1) < mid-x+1){
					ans = mid;
					right = mid-1;
				}
				else{
					left = mid+1;
				}
			}
			if(ans == -10){
				cout<<-1<<endl;
			}
			else{
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
