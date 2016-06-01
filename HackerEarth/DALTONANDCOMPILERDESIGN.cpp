#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define MOD 1000000007
int main(){
	lli test;
	cin>>test;
	lli n3;
	loop(i,test){
		cin>>n3;
		if (n3%2==0){
			cout<<n3/2<<" "<<n3/2<<endl;
		}else{
			cout<<n3/2<<" "<<(n3/2+1)<<endl;
		}
		
	}
	return 0;
}