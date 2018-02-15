/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,q;
	cin>>n>>q;
	cout<<n<<" "<<q<<endl;
	for(int i(0);i<n;i++){
		cout<<rand()%MAX<<" ";
	}
	cout<<endl;
	for(int i(0);i<q;i++){
		cout<<(rand()%n+1)<<" ";
		lli out(0);
		for(int j(0);j<rand()%1000;j++){
			out+=rand()%MAX;
		}
		cout<<out%MAX<<endl;
	}
	return 0;
}
