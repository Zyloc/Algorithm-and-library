/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	string home,s;
	cin>>n;
	cin>>home;
	map<string,lli> mp;
	for(int i=0;i<n;i++){
		cin>>s;
	}
	if(n&1){
		cout<<"contest";
	}
	else{
		cout<<"home";
	}
	return 0;
}