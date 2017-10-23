/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> input;
lli n,m,maxi,x;
bool check(lli mid){
    lli totalWood(0);
    for(int i(0);i<n;i++){
        totalWood += max(0LL,input[i]-mid);
    }
    return totalWood >= m ;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i(0);i<n;i++){
	    cin>>x;
	    maxi = max(x,maxi);
	    input.push_back(x);
	}
	lli left(0),right(maxi),ans(0);
	while(left < right){
	    lli mid(left+(right-left)/2);
	    if(check(mid)){
	        ans = max(ans,mid);
	        left = mid+1;
	    }
	    else{
	        right = mid-1;
	    }
	}
	cout<<ans<<endl;
	return 0;
}
