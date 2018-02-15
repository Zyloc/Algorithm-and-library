/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli  int
using namespace std;
const int MAX(1e6);
const int MAXMODE(1e5);
lli q;
lli andSegmentTree[MAX],orSegmentTree[MAX];
lli n;
vector<lli> input(MAX);
void create(lli left,lli  right,lli index){	
	if(left == right){
		andSegmentTree[index] = input[left];
		orSegmentTree[index] = input[left];
		return;
	}
	lli mid((left+right)>>1);
	create(left,mid,2*index+1);
	create(mid+1,right,2*index+2);
	andSegmentTree[index] = andSegmentTree[2*index+1]&andSegmentTree[2*index+2];
	orSegmentTree[index] = orSegmentTree[2*index+1]|orSegmentTree[2*index+2];
}

lli getAnd( lli tStart,lli tEnd,lli index,lli left,lli right){
	if(tStart > right or tEnd < left){
		return (1<<26)-1LL;
	}
	if(left <= tStart and right >= tEnd){
		return andSegmentTree[index];
	}
	lli mid((tStart+tEnd)>>1);
	return getAnd(tStart,mid,2*index+1,left,right)&getAnd(mid+1,tEnd,2*index+2,left,right);
}
lli getOr( lli tStart,lli tEnd,lli index,lli left,lli right){
	if(tStart > right or tEnd < left){
		return 0;
	}
	if(left <= tStart and right >= tEnd){
		return orSegmentTree[index];
	}
	lli mid((tStart+tEnd)>>1);
	return getOr(tStart,mid,2*index+1,left,right)|getOr(mid+1,tEnd,2*index+2,left,right);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	assert(n <= MAXMODE);
	assert(q <= MAXMODE);
	for(int i(0);i<n;i++){
		cin>>input[i];
		assert(input[i] >= 0);
		assert(input[i] <= MAXMODE);
	}
	create(0,n-1,0);
	lli x,k;
	while(q--){
		cin>>x>>k;
		assert(x > 0);
		assert(x <= n);
		assert(k <= MAXMODE);
		assert(k >= 0);
		x--;
		lli left(x),right(n-1);
		lli ans(x);
		while(left<=right){
			lli mid((left+right)/2);
			if(getOr(0,n-1,0,x,mid) - getAnd(0,n-1,0,x,mid) <= k){
				left = mid +1 ;
				ans = mid;
			}
			else{
				right = mid -1; 
			}
		}
		cout<<ans-x+1<<endl;
	}
	return 0;
}