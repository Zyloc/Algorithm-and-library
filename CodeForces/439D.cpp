/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> inputA,inputB;
lli magicBox(lli finalHeight){
	lli ans(0);
	for(int i(0);i<inputA.size();i++){
		ans+=max(0LL,finalHeight- inputA[i]);
	}
	for(int i(0);i<inputB.size();i++){
		ans+=max(0LL,inputB[i]-finalHeight);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,m;
	cin>>n>>m;
	for(int i(0);i<n;i++){
		cin>>x;
		inputA.push_back(x);
	}
	for(int i(0);i<m;i++){
		cin>>x;
		inputB.push_back(x);
	}
	lli left(0),right(1e10);
	while(left <= right){
		lli mid((left+right)/2);
		lli costOfMid(magicBox(mid));
		lli costOfNext(magicBox(mid+1));
		lli costOfPrev(magicBox(mid-1));
		if(costOfMid <= costOfPrev and costOfMid <= costOfNext){
			cout<<costOfMid<<endl;
			return 0;
		}
		else if(costOfMid < costOfPrev){
			left = mid + 1;
		}
		else{
			right = mid-1;
		}
	}
	return 0;
}
