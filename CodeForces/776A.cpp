/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b,temp1,temp2;
	cin>>a>>b;
	lli n;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<a<<" "<<b<<endl;
		cin>>temp1>>temp2;
		if(a == temp1){
			a = temp2;
		}
		else{
			b = temp2;
		}
	}
	cout<<a<<" "<<b<<endl;
	
	return 0;
}