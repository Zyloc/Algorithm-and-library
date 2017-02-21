/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
struct dataType{
	int start,end,mode,index;
};
bool cmp(dataType lhs,dataType rhs){
	if(lhs.start <= rhs.start){
		return true;
	}
	return false;
}
int main(){
	int n,m,x,l,r;
	cin>>n>>m;
	vector<int> v,ans(m,0);
	vector<dataType> query;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<m;i++){
		cin>>l>>r>>x;
		dataType temp;
		temp.start =  l-1;
		temp.end = r-1;
		temp.mode = x;
		temp.index = i;
		query.push_back(temp);		
	}
	sort(query.begin(),query.end(),cmp);
	int processing(0);
	for(auto x:query){
		cout<<x.index<<endl;
	}
	return 0;
}