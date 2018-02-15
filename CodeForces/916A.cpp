/*
 * 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
bool check(lli x){
	while(x){
		if(x%10 == 7){
			return true;
		}
		x/=10;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,h,m;
	cin>>x>>h>>m;
	lli counter(0);
	while(true){
		if(check(h) or check(m)){
			cout<<counter;
			return 0;
		}
		counter++;
		if(m-x < 0){
			m = (m-x+60)%60;
			h = (h+24-1)%24; 
		}
		else{
			m = (m-x)%60;
		}
	}
	return 0;
}
