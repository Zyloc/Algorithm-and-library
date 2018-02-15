/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli k;
	cin>>k;
	if(k > 36){
		cout<<-1;
		return 0;
	}
	if(k == 0){
		cout<<"1"<<endl;
	}
	for(int i(0);i<k/2;i++){
		cout<<"8";
	}
	if(k%2){
		cout<<"9"<<endl;
	}
	return 0;
}
