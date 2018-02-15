/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli  int
using namespace std;
const int MAX(524288);
lli minTree[MAX],maxTree[MAX],dp[MAX];
lli n,s,l;
vector<lli> input(MAX);
void create(lli left,lli  right,lli index){	
	if(left == right){
		minTree[index] = input[left];
		maxTree[index] = input[left];
		dp[index] = INT_MAX;
		return;
	}
	lli mid((left+right)>>1);
	create(left,mid,2*index+1);
	create(mid+1,right,2*index+2);
	minTree[index] = min(minTree[2*index+1],minTree[2*index+2]);
	maxTree[index] = max(maxTree[2*index+1],maxTree[2*index+2]);
	dp[index] = INT_MAX;
}

void updateTree(lli tStart,lli tEnd,lli index,lli updateIndex,lli updateValue){
	lli mid((tStart+tEnd)>>1);
	if(updateIndex < tStart or updateIndex > tEnd){
		return;
	}
	if(tStart == tEnd){
		dp[index] = updateValue;
		return;
	}
	updateTree(tStart,mid,2*index+1,updateIndex,updateValue);
	updateTree(mid+1,tEnd,2*index+2,updateIndex,updateValue);
	dp[index] = min(dp[2*index+1],dp[2*index+2]);
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
lli getMinimumDp( lli tStart,lli tEnd,lli index,lli left,lli right){
	if(tStart > right or tEnd < left){
		return INT_MAX;
	}
	if(left <= tStart and right >= tEnd){
		return dp[index];
	}
	lli mid((tStart+tEnd)>>1);
	return min(getMinimumDp(tStart,mid,2*index+1,left,right),getMinimumDp(mid+1,tEnd,2*index+2,left,right));
}

lli getMaximum(lli tStart,lli tEnd,lli index,lli left,lli right){
	if(tStart > right or tEnd < left){
		return INT_MIN;
	}
	if(left <= tStart and right >= tEnd){
		return maxTree[index];
	}
	lli mid((tStart+tEnd)/2);
	return max(getMaximum(tStart,mid,2*index+1,left,right),getMaximum(mid+1,tEnd,2*index+2,left,right));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>s>>l;
	for(int i(0);i<n;i++){
		cin>>input[i];
	}
	create(0,(MAX>>1)-1,0);
	updateTree(0,(MAX>>1)-1,0,n,0);
	for(int i(n-1);i>=0;i--){
    	lli left(i+l-1),right(n-1),dummy(-1);
    	while(left <= right){
    		lli mid((left+right)>>1);
    		lli maxValue(getMaximum(0,(MAX>>1)-1,0,i,mid));
    		lli minValue(getMinimum(0,(MAX>>1)-1,0,i,mid));
    		if(maxValue - minValue <= s){
    			dummy = mid;
    			left = mid + 1;
    		}
    		else{
    			right = mid - 1;
    		}
    	}
    	if(dummy != -1){
    		lli nextDummy(getMinimumDp(0,(MAX>>1)-1,0,i+l,dummy+1));
    		if(nextDummy!=INT_MAX){
    			updateTree(0,(MAX>>1)-1,0,i,nextDummy+1);
    		}
    	}
    	
    }
    lli ans(getMinimumDp(0,(MAX>>1)-1,0,0,0));
    if(ans != INT_MAX and ans != INT_MIN and ans >= 0 ){
    	cout<<ans;
    }
    else{
    	cout<<-1<<endl;
    }
    return 0;
}