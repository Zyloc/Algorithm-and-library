#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define MOD 1000000007
lli factorial(lli n){
	int i=1;
	lli fact=1;
	for(i;i<=n;i++){
		fact=(fact*i)%MOD;
	}
	return fact;	
}
int main(){
	lli number;
	cin>>number;
	cout<<factorial(number);
	return 0;
}