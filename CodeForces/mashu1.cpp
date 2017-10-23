/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli solve(lli a,lli b){
	if(a == 0){
		return 0;
	}
	if(a == 1 ){
		return b;
	}
	if(a >= b){
		return (a/b)+solve(a%b,b);
	}
	return 1LL+solve(b-a,a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli a,b;
	cin>>a>>b;
	cout<<solve(a,b)<<endl;
	return 0;
}
