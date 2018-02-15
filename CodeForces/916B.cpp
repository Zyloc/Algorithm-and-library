/*
 * 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	cin>>n>>k;
	vector<lli> answer(k);
	if(n&1){
		answer[k-1] = 1;
		n--;
		k--;
	}
	for(int i(0);i<k-1;i++){
		answer[i] = n/k;
	}
	answer[k-1] = (n/k)+(n%k);
	
	return 0;
}
