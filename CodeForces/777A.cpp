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
	cin>>n>>x;
	n = n%6;
	int a[3]={0,1,2};
	for(int i=0;i<n;i++){
		if(i&1){
			swap(a[0],a[1]);
		}
		else{
			swap(a[1],a[2]);
		}
	}
	
	return 0;
}