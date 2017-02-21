/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli k,a,b;
	cin>>k>>a>>b;
	if(a/k == 0  and b%k != 0){
		cout<<-1<<endl;
		return 0;
	}
	if(b/k == 0  and a%k != 0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<a/k+b/k<<endl;
	return 0;
}