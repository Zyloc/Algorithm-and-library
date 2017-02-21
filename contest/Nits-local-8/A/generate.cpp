#include <bits/stdc++.h>
#define lli long long int

using namespace std;
int main(){
	lli a,b,t,max;
	cin>>t>>max;
	cout<<t<<endl;
	while(t--){
		a = rand()%max+1;
		if(t&1){
			b = rand()%a;
		}
		else{
			b = rand()%a+1;
		}
		cout<<a<<" "<<b<<endl;
	}
}