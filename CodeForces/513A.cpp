/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	if(n1 != n2){
		if(n1 > n2){
			cout<<"First";
		}
		else{
			cout<<"Second";
		}
	}
	else{
		cout<<"Second";
	}
	return 0;
}