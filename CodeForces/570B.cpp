/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	cin>>n>>k;
	lli leftSide(k-1),rightSide(n-k);
	if(leftSide >= rightSide){
		cout<<max(k-1,(lli)1);
	}
	else if(rightSide > leftSide){
		cout<<k+1;
	}
	return 0;
}