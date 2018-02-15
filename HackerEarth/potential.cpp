/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli int
using namespace std;
lli n,q;
//1048576
const int MAX(1048576);
struct inception{
	lli position,x,p,maxi;
};
struct node{
	//vector<pair<lli,lli> > temp,maxVector;
	//vector<lli> maxVector;
	vector<inception> temp;
};

node segmentTree[MAX];
vector<lli> X(MAX),P(MAX);

node merge(node left , node right){
	for(int i(1);i<=right.temp.size();i++){
		left.temp.push_back(right.temp[i-1]);
		left.maxVector.push_back({right.temp[i-1].first+min(right.temp[i-1].second)});
	}
	sort(left.maxVector.begin(),left.maxVector.end());
	return left;
}

void build(lli tStart,lli tEnd,lli position){
	if(tStart == tEnd){
		node dummy;
		/*dummy.temp.push_back({X[tStart],P[tStart]});
		dummy.maxVector.push_back(X[tStart]+min(P[tStart],0));
		dummy.position = tStart;
		segmentTree[position] = dummy;
*/		return ;
	}
	lli mid((tStart+tEnd)>>1);
	build(tStart,mid,2*position+1);
	build(mid+1,tEnd,2*position+2);
	segmentTree[position] = merge(segmentTree[2*position+1],segmentTree[2*position+2]);
}

void update(lli tStart,lli tEnd,lli position,lli updateIndex){
	if(tStart > updateIndex or tEnd < updateIndex){
		return ;
	}
	if(tStart == tEnd){
		segmentTree[position].temp[0] = {X[updateIndex],P[updateIndex]};
		segmentTree[position].maxVector[0] = X[updateIndex]+min(P[updateIndex],0);
		return;
	}
	lli mid((tStart+tEnd)>>1);
	update(tStart,mid,2*position+1,updateIndex);
	update(mid+1,tEnd,2*position+2,updateIndex);
	for(int i(0);i<segmentTree[position].maxVector.size();i++){
		if(segmentTree[position].position == updateIndex){
			segmentTree[position].maxVector[i]
		}	
	}
	
	// change this line if you get TLE .. i am too lazy to write code help me please :P
	//segmentTree[position] = merge(segmentTree[2*position+1],segmentTree[2*position+2]);

}

lli rangeMaximumQuery(lli tStart,lli tEnd,lli qStart,lli qEnd,lli position){
	if(tStart > qEnd or tEnd < qStart){
		return INT_MIN;
	}
	if(tStart <= qStart and tEnd >= qEnd){
		return segmentTree[position].maxi[0].first;
	}
	lli mid((tStart+tEnd)>>1);
	return max(rangeMaximumQuery(tStart,mid,qStart,qEnd,2*position+1),rangeMaximumQuery(mid+1,tEnd,qStart,qEnd,2*position+2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y,z;
	cin>>n>>q;
	for(int i(0);i<n;i++){
		cin>>X[i];
	}
	for(int i(0);i<n;i++){
		cin>>P[i];	
	}
	build(0,(MAX>>1)-1,0);
	for(int i(0);i<q;i++){
		cin>>x;
		if(x == 1){
			cin>>y>>z;
			--y;
			X[y] = z;
			update(0,(MAX>>1)-1,0,y);
		}
		else if(x == 2){
			cin>>y>>z;
			--y;
			P[y] = z;
			update(0,(MAX>>1)-1,0,y);
		}
		else{
			cin>>y>>z;
			y--,z--;	
			cout<<rangeMaximumQuery(0,(MAX>>1)-1,y,z,0)<<endl;
		}
	}
	return 0;
}
