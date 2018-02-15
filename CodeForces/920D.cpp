/*
 * Richie  who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+7);
lli divisors[MAX];
lli n,m;
lli tree[10*MAX];
bool isRecursive[10*MAX];
vector<lli> input;
void seive(){
	for(int i(1);i<MAX;i++){
		for(int j(i);j<MAX;j+=i){
			divisors[j]++;
		}
	}
}
void buildTree(lli l,lli r,lli pos){
	if(l == r){
		if(input[l] == 1 or input[l] == 2){
			isRecursive[pos] = true;
		}
		tree[pos] = input[l];
		return;
	}
	lli mid((l+r)/2);
	buildTree(l,mid,2*pos+1);
	buildTree(mid+1,r,2*pos+2);
	tree[pos] = tree[2*pos+1]+tree[2*pos+2];
	isRecursive[pos] = isRecursive[2*pos+1] and isRecursive[2*pos+2]; 
}
void update(lli l,lli r,lli pos,lli updateStart,lli updateEnd){
	if(updateEnd < l or updateStart > r){
		return;
	}
	if(isRecursive[pos]){
		return ;
	}
	if(l == r){
		if(divisors[tree[pos]] == 1 or divisors[tree[pos]] == 2){
			isRecursive[pos] = true;
		}
		tree[pos] = divisors[tree[pos]];
		return;
	}
	lli mid((l+r)/2);
	update(l,mid,2*pos+1,updateStart,updateEnd);
	update(mid+1,r,2*pos+2,updateStart,updateEnd);
	tree[pos] = tree[2*pos+1]+tree[2*pos+2];
	isRecursive[pos] = isRecursive[2*pos+1] and isRecursive[2*pos+2];
}
lli get(lli tL,lli tR,lli pos,lli l,lli r){
	if(tL > r or tR < l){
		return 0;
	}
	if(l <= tL and r >= tR){
		return tree[pos];
	}
	lli mid((tL+tR)/2);
	return get(tL,mid,2*pos+1,l,r)+get(mid+1,tR,2*pos+2,l,r);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	seive();
	lli x;
	cin>>n>>m;
	for(int i(0);i<n;i++){
		cin>>x;
		input.push_back(x);
	}
	buildTree(0,n-1,0);
	while(m--){
		lli type,l,r;
		cin>>type>>l>>r;
		if(type == 1){
			update(0,n-1,0,l-1,r-1);
		}
		else{
			cout<<get(0,n-1,0,l-1,r-1)<<endl;
		}
	}
	return 0;
}
