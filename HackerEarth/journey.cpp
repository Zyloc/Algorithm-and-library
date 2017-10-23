/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct dataType{
	lli decrement,capacity,cost;
	dataType(){
		decrement = 0;
		capacity = 0;
		cost = 0;
	}
};
lli n,m;
vector<dataType> input;
//1048576
const int MAX(1048576);
lli tree[MAX];
vector<lli> prefix;
lli create(lli left,lli  right,lli index){	
	if(left == right){
		tree[index] = 1e18;
		return tree[index];
	}
	lli mid((left+right)/2);
	tree[index] = min(create(left,mid,2*index+1),create(mid+1,right,2*index+2));
	return tree[index];
}
void updateTree(lli tStart,lli tEnd,lli index,lli updateIndex,lli updateValue){
	lli mid((tStart+tEnd)/2);
	if(updateIndex < tStart or updateIndex > tEnd){
		return;
	}
	if(tStart == tEnd){
		tree[index] = updateValue;
		return;
	}
	updateTree(tStart,mid,2*index+1,updateIndex,updateValue);
	updateTree(mid+1,tEnd,2*index+2,updateIndex,updateValue);
	tree[index] = min(tree[2*index+1],tree[2*index+2]);
}
lli getMinimum(lli tStart,lli tEnd,lli index,lli left,lli right){
	if(tStart > right or tEnd < left){
		return 1e18+1;
	}
	if(left <= tStart and right >= tEnd){
		return tree[index];
	}
	lli mid((tStart+tEnd)/2);
	return min(getMinimum(tStart,mid,2*index+1,left,right),getMinimum(mid+1,tEnd,2*index+2,left,right));
}
lli search(lli value){
	lli left(0),right(n-1),ans(-1);
	while(left <= right){
		lli mid((left+right)/2);
		//cout<<prefix[mid-1]<<" "<<mid<<endl;
		if(prefix[mid] > value){
			ans = mid;
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return ans;
}
void magicBox(lli index){
	if(index == 0){
		if(input[index].capacity >= input[index].decrement){
			lli idx(search(input[index].capacity));
			//cout<<ca<<endl;
			if(idx!=-1){
				//cout<<idx<<endl;;
				lli minValue(getMinimum(0,MAX/2-1,0,0,idx));
				updateTree(0,MAX/2-1,0,index,input[index].cost+minValue);	
			}
		}
	}
	else{
		lli idx(search(prefix[index-1]+input[index].capacity));
		cout<<index<<" "<<idx<<endl;
		lli minValue(getMinimum(0,MAX/2-1,0,index,idx));
		updateTree(0,MAX/2-1,0,index,input[index].cost+minValue);
		//cout<<getMinimum(0,MAX/2-1,0,index,index)<<endl;	
	}
	//cout<<index<<" "<<getMinimum(0,MAX/2-1,0,index,index)<<endl;	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x;
	cin>>n>>m;
	dataType temp;
	for(int i(0);i<n-1;i++){
		cin>>x;
		if(i == 0){
			prefix.push_back(x);
		}
		else{
			prefix.push_back(x+prefix[i-1]);
		}
		temp.decrement = x;
		input.push_back(temp);
	}
	prefix.push_back(INT_MAX);
	for(int i(0);i<n-1;i++){
		cin>>x;
		temp = input[i];
		temp.capacity = x;
		input[i] = temp;
	}
	for(int i(0);i<n-1;i++){
		cin>>x;
		temp = input[i];
		temp.cost = x;
		input[i]= temp;
	}
	create(0,MAX/2-1,0);
	updateTree(0,MAX/2-1,0,n-1,0);
	
	/*for(int i(0);i<n-1;i++){
		cout<<i<<" "<<prefix[i]<<endl;
	}*/
	//cout<<search(5)<<endl;
	for(int i(n-2);i>=0;i--){
		magicBox(i);
	}
	lli q;
	for(int i(0);i<m;i++){
		cin>>q;
		lli value(search(q));
		//cout<<value;
		if(value == -1 and getMinimum(0,MAX/2-1,0,0,0)==1e18){
			cout<<-1<<endl;
		}
		else{
			lli minValue(getMinimum(0,MAX/2-1,0,0,value));
			cout<<(minValue==1e18?-1:minValue)<<endl;
		}
	}
	return 0;
}
