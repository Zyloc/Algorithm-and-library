/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct dataType{
	int value,index;
};
bool cmp(dataType lhs,dataType rhs){
	return lhs.value > rhs.value or (lhs.value == rhs.value and lhs.index > rhs.index);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,x,y;
		cin>>n;
		vector<dataType> v;
		for(int i=0;i<n;i++){
			cin>>x;
			dataType temp;
			temp.value = x;
			temp.index = i;
			v.push_back(temp);
		}
		sort(v.begin(),v.end(),cmp);
		for(int i(0);i<n;i++){
			cout<<v[i].index<<" ";
		}
	}
	return 0;
}