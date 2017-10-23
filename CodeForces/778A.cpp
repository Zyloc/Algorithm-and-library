/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	map<lli,lli> A,B;
	for(int i=0;i<n;i++){
		cin>>x;
		A[x]++;
	}
	for(int i=0;i<n;i++){
		cin>>x;
		B[x]++;
	}
	lli ans(0);
	for(int i=0;i<=5;i++){
		if(A[i]!=B[i]){
			if((A[i]+B[i])%2 == 0){
				ans += abs(A[i]-B[i])/2;
			}
			else{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	cout<<ans/2<<endl;
	return 0;
}