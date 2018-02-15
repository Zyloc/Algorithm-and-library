/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b;
	cin>>a;
	b = a;
	reverse(b.begin(),b.end());
	if(a == b){
		cout<<a;
		return 0;
	}
	else{
		cout<<a+b<<endl;
	}
	return 0;
}
