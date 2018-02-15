/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli  int
using namespace std;
const int MAX(524288);
lli minTree[MAX];
lli n;
vector<lli> input(MAX);
void create(lli left,lli  right,lli index){	
	if(left == right){
		minTree[index] = input[left];
		return;
	}
	lli mid((left+right)>>1);
	create(left,mid,2*index+1);
	create(mid+1,right,2*index+2);
	minTree[index] = min(minTree[2*index+1],minTree[2*index+2]);
}

void updateTree(lli tStart,lli tEnd,lli index,lli updateIndex,lli updateValue){
	lli mid((tStart+tEnd)>>1);
	if(updateIndex < tStart or updateIndex > tEnd){
		return;
	}
	if(tStart == tEnd){
		minTree[index] = updateValue;
		return;
	}
	updateTree(tStart,mid,2*index+1,updateIndex,updateValue);
	updateTree(mid+1,tEnd,2*index+2,updateIndex,updateValue);
	minTree[index] = min(minTree[2*index+1],minTree[2*index+2]);
}

lli getMinimum( lli tStart,lli tEnd,lli index,lli left,lli right){
	if(tStart > right or tEnd < left){
		return INT_MAX;
	}
	if(left <= tStart and right >= tEnd){
		return minTree[index];
	}
	lli mid((tStart+tEnd)>>1);
	return min(getMinimum(tStart,mid,2*index+1,left,right),getMinimum(mid+1,tEnd,2*index+2,left,right));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>s>>l;
	for(int i(0);i<n;i++){
		cin>>input[i];
	}
	create(0,(MAX>>1)-1,0);
	updateTree(0,(MAX>>1)-1,0,5,10);
    return 0;
}