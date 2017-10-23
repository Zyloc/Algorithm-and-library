/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,m,k;
lli check(lli number){
	lli countNumber(0);
	for(int i(1);i<=n;i++){
		countNumber += min(number/i,m);
	}
	return countNumber;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	lli left(1),right(n*m),ans(1);
	while(left <= right){
		lli mid((left+right)/2);
		if(check(mid) >= k){
			right = mid - 1;
			ans = mid;	
		}
		else{
			left = mid + 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
