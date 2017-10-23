/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		double n,v1,v2;
		cin>>n>>v1>>v2;
		if(2.0*(n/v2) <= (n*sqrt(2))/v1){
			cout<<"Elevator"<<endl;
		}
		else{
			cout<<"Stairs"<<endl;
		}
	}
	return 0;
}
