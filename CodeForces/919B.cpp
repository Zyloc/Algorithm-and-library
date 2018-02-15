/*
 * Richie Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli check(lli n){
	lli sum(0);
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli k;
	cin>>k;
	lli iterator(1);
	while(k){
		if(check(iterator) == 10){
			k--;
		}
		iterator++;
	}
	cout<<iterator-1<<endl;
	return 0;
}
