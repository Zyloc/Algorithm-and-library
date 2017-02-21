/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct dataType{
	int index,value;
};
struct cmp{
	bool operator()(dataType lhs,dataType rhs){
		if(lhs.value < rhs.value){
			return true;
		}
		else if(lhs.value == rhs.value){
			return lhs.index>rhs.index;
		}
		return false;
	}
};	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli numberOfplayers,balls,x;
	cin>>numberOfplayers>>balls;
	priority_queue<dataType,vector<dataType >,cmp> pq;
	for(int i=0;i<numberOfplayers;i++){
		cin>>x;
		dataType temp;
		temp.value = x;
		temp.index = i+1;
		pq.push(temp);
	}
	for(int i=0;i<balls;i++){
		cout<<pq.top().index<<" ";
		lli first(pq.top().value),second(pq.top().index);
		first--;
		pq.pop();
		if(first != 0){
			dataType temp;
			temp.value = first;
			temp.index = second;
			pq.push(temp);
		}
	}
	return 0; 
}