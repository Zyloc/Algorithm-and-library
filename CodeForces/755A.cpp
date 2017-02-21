/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
bool solve(int n,int m){
	for(int i=2;i<=sqrt(n*m+1);i++){
		if((n*m+1)%i ==0){
			return true;
		}
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	int start(1);
	while(true){
		if(solve(n,start)){
			cout<<start;
			return 0;
		}
		start++;
	}
	return 0;
}