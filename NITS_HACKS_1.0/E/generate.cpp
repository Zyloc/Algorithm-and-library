/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k,x;
	cin>>n>>k>>x;
	cout<<n<<" "<<k<<" "<<x<<endl;
	for(int i(0);i<n;i++){
		cout<<2<<" "<<rand()%3+1<<endl;
	}
	return 0;
}
