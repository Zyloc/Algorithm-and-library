/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(101);
int input[MAX][MAX];
lli n,x,d;
lli getCost(lli finalValue){
	lli ans(0);
	for(int i(0);i<n;i++){
		for(int j(0);j<n;j++){
			ans+=abs(input[i][j]-finalValue)/d;
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>d;
	set<lli> st;
	for(int i(0);i<n;i++){
		for(int j(0);j<n;j++){
			cin>>input[i][j];
			st.insert(input[i][j]%d);
		}	
	}
	if(st.size() == 1){
		lli left(0),right(1e10);
		while(left <= right){
			lli mid((left+right)/2);
			lli costOfMid(getCost(mid));
			lli costOfPrev(getCost(mid-1));
			lli costOfNext(getCost(mid+1));
			if(costOfMid <= costOfPrev and costOfMid <= costOfNext){
				cout<<costOfMid<<endl;
				return 0;
			}
			else if(costOfMid < costOfNext){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
	}
	else{
		cout<<-1;
	}
	return 0;
}
